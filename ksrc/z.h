#define Qs(b) P(b,ws(s))
#define Q(z) r(z,P(!r,0))
#define mn (ma?:na)
#define Vr *(V*)rV
#include"_.h"
#define AS(f,s,x...) ZU __attribute((naked))f(x){asm(s"ret");}
#if __x86_64
#define O(f,i) AS(f,"mov %rcx,%r10;mov $"#i",%rax;call b_k;",Ux,...)
AS(ut,"rdtsc;shl $32,%rdx;or %rdx,%rax;")UV(bg,B(ia32_cvtb2mask512)(a))
#else
#define O(f,i) AS(f,"mov x16,"#i"\nldr x1,[sp]\nldr x2,[sp,8]\nldr x3,[sp,16]\nmov x4,0\nmov x5,x4\nsvc 0\n",Ux,...)
AS(ut,"mrs x0,cntvct_el0\nmov x1,100\nmul x0,x0,x1\n")
#endif
#if linux
Z2 M;O(_k,60)O(_w,0)O(w_,1)O(_d,3)O(d_,2)O(_n,5)O(m_,9)O(_m,11)
#else
Z2 M=1;O(_w,3)O(w_,4)O(_d,6)O(d_,5)O(_n,189)O(m_,197)O(_m,73)
#endif
F(ms,ii=d_(x,0);P(i>>31,0)Ub[24];x=!_n(i,b)&1&b[M?0:3]>>(M?47:15)?b[M?12:6]:0;x?m_(a,x,1,0x12,i,0):0;_d(i);x) //m_(a?:A,x,3,i?0x12:M?0x1042:0x4022,i,0)
#define ss i0*s
#define Vs *(V*)s
#define s(g,z) D(U,g,z,ss)
#define is(g,z) D(U,g,z,ii,ss) //U_(write,w_(i,s,x),ii,ss,Ux)
Z0*L=__DATE__"(c)arthur whitney(l)MIT",*P=":+-*%&|<>=~.!@?#_^,$LMSA..ERZ'/\\;()",B=32,b[256];is(i$,48>*s?(i2)-i$(i-1,s+1):r(0,i(i,r=10*r+s[i]-48)))
UV(ib,iu(~bg(a)))is(ic,ib((i0)i!=Vs))
is(w0,w_(2,s,i);wc(10);0)
s(ws,w0(ic(0,s),s))
Vf(d0,46==a|10>a-48)Vf(d1,1>I0|32==a|101==a)

extern U k(ii,U,U);f(r_,ax?x:k(0,0,x))f(_r,ax?x:k(15,0,x))g(a_,k(13,r_(x),ti(i)))
#define sx ((i0*)k(0,x,0))
#define ins(g,z) D(U,g,z,ii,in,ss)
#define sd i0*d
is(ns,R(2,i,Vr=Vs))f(_v,k(13,0,x))ins(nc,nu(b(i)&bg((i0)n==Vs)))_i(wl,w0(i,b))f(wb,i(64,b[i]=48|1&x>>i)wl(64);x)f(wu,i(16,ij=15&x>>60-4*i;b[i]="0W"[9<j]+j)wl(16);x)
ZU w(ss),qs(ss),q(ii),ps(ii,ss),wx(U);is(c,*(V*)b=Vs;b[ic(i,b)]=10==i?0:10)s(y,c(0,s);w(b))_i(o,3>i-61)_i(v,B>i-B)
Z2 I[]={1,10,1e2,1e3,1e4,1e5,1e6,1e7,1e8,1e9};



