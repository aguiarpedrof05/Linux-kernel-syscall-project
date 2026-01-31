#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/syscall.h>

/* Número definido na syscall_64.tbl do kernel compilado */
#define __NR_helloworld 548

/* Variável atômica para contagem segura dentro de handlers de sinal */
volatile sig_atomic_t helloworld_count = 0;

/* Handler para o alarme periódico */
void alarm_handler(int signum) {
    syscall(__NR_helloworld); // Invoca a syscall personalizada
    helloworld_count++;
    alarm(3); // Reagenda o alarme para daqui a 3 segundos
}

/* Handler para encerrar o programa de forma limpa (Ctrl+C) */
void ctrl_c_handler(int signum) {
    printf("\nPrograma finalizado. A chamada 'helloworld' foi invocada %d vezes.\n", helloworld_count);
    exit(0);
}

int main() {
    /* Registra os manipuladores de sinais */
    signal(SIGALRM, alarm_handler);
    signal(SIGINT, ctrl_c_handler);

    printf("Programa iniciado. Pressione Ctrl+C para sair.\n");
    printf("A syscall 'helloworld' sera chamada a cada 3 segundos...\n");

    /* Dispara o primeiro alarme */
    alarm(3);

    /* Loop infinito esperando por sinais (economiza CPU) */
    while (1) {
        pause(); 
    }

    return 0;
}