namespace geo3D{
    const double PI = acos(-1);
    const double eps = 1e-10;
    double rand_eps(){
        return ((double)rand()/RAND_MAX-0.5)*eps;
    }
    struct PT{
        double x,y,z;
        PT() {x=0,y=0,z=0;}
        PT(double a,double b,double c) {x=a,y=b,z=c;}
        friend ostream &operator<<(ostream &o,const PT &X){
            o<<X.x<<' '<<X.y<<' '<<X.z;return o;}
        friend istream &operator>>(istream &i,PT &X){ 
            i>>X.x>>X.y>>X.z;return i;}
        PT operator-() {return PT(-x,-y,-z);}
        PT operator+(const PT &B){
            return {x+B.x,y+B.y,z+B.z};}
        PT operator-(const PT &B){
            return {x-B.x,y-B.y,z-B.z};}
        PT operator*(const double k){return {x*k,y*k,z*k};}
        friend PT operator*(const double k,PT T){return T*k;}
        PT operator/(const double k){return {x/k,y/k,z/k};}
        double operator&(const PT &t){//点乘
            return x*t.x+y*t.y+z*t.z;}
        PT operator*(const PT &t){//叉乘
        return {y*t.z-t.y*z,z*t.x-x*t.z,x*t.y-y*t.x};}
        bool operator==(const PT &Y){
            return (x==Y.x)&&(y==Y.y)&&(z==Y.z);}
        bool operator!=(const PT &Y){
            return (x!=Y.x)||(y!=Y.y)||(z!=Y.z);}
        double size(){return sqrt(x*x+y*y+z*z);}
        void shake(){
            x+=rand_eps(),y+=rand_eps(),z+=rand_eps();}
    };
    
    struct LI{
        PT st,ed;
    };
    
    struct PL{
        PT v[3];//逆时针存3个点
        PT norm(){//法向量
            return (v[1]-v[0])*(v[2]-v[0]);
        }
        double area(){return norm().size()/2;}
        bool above(PT a){//点a是否在上方
            return ((a-v[0])&norm())>=0;}
    };
    
    struct IPL{
        int v[3];
    };
}
 
using namespace geo3D;