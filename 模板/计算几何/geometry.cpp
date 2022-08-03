namespace geometry{
    const double PI = acos(-1);
    const double eps = 1e-8;
    int sign(double x){
        if(fabs(x)<eps) return 0;
        if(x<0) return -1;
        return 1;
    }
    struct PT{
        double x,y;
        PT() {x=0,y=0;}
        PT(double a,double b) {x=a,y=b;}
        friend ostream &operator<<(ostream &o,const PT &X){
            o<<X.x<<' '<<X.y;return o;}
        friend istream &operator>>(istream &i,PT &X){ 
            i>>X.x>>X.y;return i;}
        PT operator-() {return PT(-x,-y);}
        PT operator+(const PT &B){return {x+B.x,y+B.y};}
        PT operator-(const PT &B){return {x-B.x,y-B.y};}
        PT operator*(const double k){return {x*k,y*k};}
        friend PT operator*(const double k,PT T){return T*k;}
        PT operator/(const double k){return {x/k,y/k};}
        bool operator==(const PT &Y){
            return (!sign(x-Y.x))&&(!sign(y-Y.y));}
        bool operator!=(const PT &Y){
            return sign(x-Y.x)||sign(y-Y.y);}
        double size(){return sqrt(x*x+y*y);}
        PT rotate(double angle){
            //返回顺时针旋转angle弧度,不改变自身
            double nx=x*cos(angle)+y*sin(angle);
            double ny=-x*sin(angle)+y*cos(angle);
            return {nx,ny};}
        double get_angle(){return atan2(y,x);}
    };
 
    struct LI{
        PT st, ed;//起点，终点
        double get_angle()const{return atan2(ed.y-st.y,ed.x-st.x);}
    };
     
    struct CI{
        PT p;
        double r;
        CI() {p={0,0},r=0;}
        CI(PT a,double b) {p=a,r=b;}
        CI(double a,double b,double c){p={a,b},r=c;}
        friend ostream &operator<<(ostream &o,const CI &X){
            o<<X.p<<' '<<X.r;return o;}
        friend istream &operator>>(istream &i,CI &X){ 
            i>>X.p>>X.r;return i;}
        CI operator-() {return CI(-p,-r);}
        CI operator+(const CI &B){return {p+B.p,r+B.r};}
        CI operator-(const CI &B){return {p-B.p,r-B.r};}
        CI operator*(const double k){return {p*k,r*k};}
        friend CI operator*(const double k,CI T){return T*k;}
        bool operator==(const CI &Y){
            return (p==Y.p)&&(!sign(r-Y.r));}
        bool operator!=(const CI &Y){
            return (p!=Y.p)||sign(r-Y.r);}
        double area(){return PI*r*r;}
        double girth(){return 2*PI*r;}
    };
     
    namespace geofunc{
    double len(PT a,PT b){return (a-b).size();}
    double cdis(CI a,CI b){return len(a.p,b.p);}
    double dot(PT a, PT b) {return a.x*b.x+a.y*b.y;}
    double cross(PT a,PT b){return a.x*b.y-b.x*a.y;}
    //B在A的逆时针方向为正
    double area(PT o,PT a,PT b){return cross(o-a,o-b)/2;}
    bool aless(const LI& a,const LI& b){
        double A = a.get_angle(), B = b.get_angle();
        if (!sign(A-B)) return area(a.st, a.ed, b.ed) < 0;
        return A < B;
    }
    bool xless(const PT &A,const PT &B){
        if(sign(A.x-B.x)==0) return A.y<B.y;
        return A.x<B.x;
    }
    double angle(PT a,PT b){//夹角
        return acos(dot(a,b)/a.size()/b.size());
    }
    double ang(double rad) {return rad/PI*180;}
    double rad(double ang) {return ang/180*PI;}
    double area(double a,double b,double c){
        double p=(a+b+c)/2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
    double area(PT OA,PT OB){return cross(OA,OB)/2;}
    double cos_law(double a,double b,double c){
        double cosC=(a*a+b*b-c*c)/(2*a*b);
        return acos(cosC);
    }
    PT line_x_line(PT p,PT v,PT q,PT w){
        //以p为起点,q为方向向量的直线l1与l2的交点
        PT u = p - q;
        double t = cross(w, u) / cross(v, w);
        return p + v * t;
    }
    PT line_x_line(LI l1,LI l2){
        return line_x_line(l1.st,l1.ed-l1.st,l2.st,l2.ed-l2.st);
    }
    double dist2line(PT p,PT l,PT r){
        //点p到直线(l->r)的距离
        PT v1 = r - l, v2 = p - l;
        return fabs(cross(v1, v2) / v1.size());
    }
    double dist2line(PT p,LI l){return dist2line(p,l.st,l.ed);}
    double dist2sgt(PT p,PT l,PT r){
        //点p到线段(l->r)的距离
        if (l == r) return (p-l).size();
        PT v1 = r - l, v2 = p - l, v3 = p - r;
        if(sign(dot(v1, v2))<0) return v2.size();
        if(sign(dot(v1, v3))>0) return v3.size();
        return dist2line(p,l,r);
    }
    double dist2sgt(PT p,LI l){return dist2sgt(p,l.st,l.ed);}
    PT line_proj(PT p,PT l,PT r){
        //点p在直线(l->r)的投影
        PT v = r - l;
        return l+v*(dot(v,p-l)/dot(v,v));
    }
    PT line_proj(PT p,LI l){return line_proj(p,l.st,l.ed);}
    bool on_sgt(PT p,PT l,PT r){
        //点p是否在线段(l,r)上
        return sign(cross(p-l,p-r))==0&&\
            sign(dot(p-l,p-r))<=0;
    }
    bool on_sgt(PT p,LI l){return on_sgt(p,l.st,l.ed);}
    bool sgt_x_sgt(PT l1,PT r1,PT l2,PT r2){
        //判断线段(l1->r1)与线段(l2->r2)是否相交
        double c1,c2,c3,c4;
        c1=cross(r1-l1,l2-l1),c2=cross(r1-l1,r2-l1);
        c3=cross(r2-l2,r1-l2),c4=cross(r2-l2,l1-l2);
        return sign(c1)*sign(c2)<=0&&\
            sign(c3)*sign(c4)<=0;
    }
    bool sgt_x_line(PT a,PT b,PT l,PT r){
        //判断线段(a->b)与直线(l->rr)是否相交
        return sign(area(a,l,r))*sign(area(b,l,r)) <= 0;
    }
    LI get_mid_line(PT a,PT b){
        //中垂线
        PT st=(a+b)/2;
        PT dl=(b-a).rotate(PI/2);
        return {st,st+dl};
    }
    CI get_circle(PT a,PT b,PT c){
        //三点构成圆
        LI l1=get_mid_line(a,b);
        LI l2=get_mid_line(a,c);
        PT p=line_x_line(l1,l2);
        double r=len(p,a);
        return {p,r};
    }
    double polygon_area(PT p[], int n){
        //求多边形面积（不一定是凸多边形）
        //p[]通常按逆时针存储所有点,n是边数
        double s = 0;
        for(int i = 1; i + 1 < n; i ++ )
            s+=cross(p[i]-p[0],p[i+1]-p[i]);
        return s / 2;
    }
    }
    using namespace geofunc;
}
 
using namespace geometry;