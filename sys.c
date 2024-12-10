int main(int,char**);
__attribute__((__section__(".text.startup"))) 
void _start(){
 asm volatile ("subq $8,%%rsp"::);
 char*v[2]={"k",0};
 main(1,v);
 asm volatile ("addq $8,%%rsp"::);
}

#include<libBareMetal.c>
static char b_in(void) {
 for(;;) {
  asm volatile ("hlt"::);
  char c=b_input();
  if(!c) continue;
  c=c==0x1c?'\n':c;
  b_output(&c,1);
  return c;
}}
long input_read(long fd,char*s,long n) {
 if(n<1)return 0;
 long i=0;
 for(;i<n-1;i++) {
  char c=b_in();
  s[i]=c;
  if(c=='\n') break;
 }
 s[i+1]=0;
 return i;
}
