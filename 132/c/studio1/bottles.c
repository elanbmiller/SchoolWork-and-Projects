/*
Elan Miller and 
Sophie Elliott
*/

#include <stdio.h>

int main(int argc, char** argv){

int bottles = 99;
for(bottles; bottles > 0; bottles--){
if(bottles == 1){
printf("%d  bottle of beer on the wall\n",bottles);
}
else{
printf("%d bottles of beer on the wall\n",bottles);
}

}
return 0;
}
