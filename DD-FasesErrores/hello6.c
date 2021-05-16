int printf(const char * restrict s, ...);

int main(void){
    int i=42;
    printf("La respuesta es %d\n",i); 
}
//Se agrega la variable i dentro del printf