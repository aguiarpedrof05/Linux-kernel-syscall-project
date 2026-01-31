# Linux Kernel Custom Syscall & Signal Handling

Este projeto demonstra a modificação do Kernel do Linux (v6.17.3) para implementação de uma nova System Call (syscall) e o desenvolvimento de um software em espaço de usuário para automação de chamadas via sinais.

## 🚀 Destaques Técnicos
- **Kernel Hacking**: Adição da syscall `sys_helloworld` ao código-fonte do Kernel.
- **Sistemas Operacionais**: Modificação da tabela de chamadas (`syscall_64.tbl`) e recompilação completa do kernel.
- **Programação em C (Baixo Nível)**: Uso de handlers de sinais (`SIGALRM` e `SIGINT`) para controle de processos.
- **Troubleshooting**: Resolução de erros críticos de assinatura SSL e conflitos de módulos DKMS/Nvidia durante o processo de compilação.

## 📂 Estrutura do Projeto
- `/src/helloworld.c`: Implementação da syscall dentro do Kernel usando `printk`.
- `/src/parte2.c`: Programa em C que utiliza `alarm()` e `pause()` para invocar a syscall a cada 3 segundos.
- `Makefile`: Script de automação para compilação do programa de teste.
- `/docs/relatorio.pdf`: Documentação acadêmica detalhada com prints de execução.

## 🛠️ Como Executar (Ambiente de Teste)
Para rodar o programa que testa a syscall (necessário estar rodando o Kernel modificado):

1. Compile o programa:
   ```bash
   make
