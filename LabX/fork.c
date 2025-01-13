int main ()
{

pid = fork();
if (pid ==0){
printf(" 1st PID= %d\n", getpid());


pid2 = fork();
if (pid2==0) {
printf(" 2nd PID= %d\n", getpid());



pid3 = fork();
if (pid3==0) {
printf(" 3rd PID= %d\n", getpid());
}}}

return 0;}
