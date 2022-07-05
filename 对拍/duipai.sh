:again  
# data > input.txt
AC < input.txt > AC_output.txt  
WA < input.txt > WA_output.txt  
fc AC_output.txt WA_output.txt  
if not errorlevel 1 goto again  
pause 