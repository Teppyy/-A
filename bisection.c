#include<stdio.h>
#include<math.h>

double Function1(double x){
  double y;
  y = x - 1.2 * exp(-x);
  return y;
}

double Bisection(double a, double b, double eps){
  double c, fa, fb, fc;
 //shishido

  while(1){
    c = (a+b)/2;
   
    printf("a = %+.6f, b = %+.6f, c = +%6f\n",a,b,c);
    if(fabs(a-b)<2*eps){
      break;
    }
    fa = Function1(a);
    fb = Function1(b);
    fc = Function1(c);
    if(fc == 0){
      break;
    }
    else if((fc > 0 && fa > 0) || (fc < 0 && fa < 0)){
      a = c;
     }
    else if((fc > 0 && fb > 0) || (fc < 0 && fb < 0)){
      b = c;
    }
  }
  return c;

}
int main(void){
  double x;
  x = Bisection(0,3,1e-6);
  printf("answer = %+.6f\n",x);

  return 0;
}
