#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ESTUDANTES 15
#define MAX_ESTUDANTES_POR_DISCIPLINA 10

typedef struct {
    char nome[100];
} Professor;

typedef struct {
    char nome[100];
    int carga_horaria;
    Professor professor_responsavel;
} Disciplina;

typedef struct {
    char nome[100];
    int idade;
} Estudante;

void bubble_sort(Estudante estudantes[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (estudantes[j].idade > estudantes[j + 1].idade) {
                Estudante temp = estudantes[j];
                estudantes[j] = estudantes[j + 1];
                estudantes[j + 1] = temp;
            }
        }
    }
}

int le_valida_idade(int idade) {
    return idade >= 16 && idade <= 26;
}

int main() {
    int i;
		
	Professor professores[3];
    Disciplina disciplinas[2];
    Estudante estudantes[MAX_ESTUDANTES];

    for (i = 0; i < 3; i++) {
        printf("Cadastro do Professor %d\n", i + 1);
        printf("Nome: ");
        fgets(professores[i].nome, sizeof(professores[i].nome), stdin);
    }

    for (i = 0; i < 2; i++) {
        printf("Cadastro da Disciplina %d\n", i + 1);
        printf("Nome: ");
        fgets(disciplinas[i].nome, sizeof(disciplinas[i].nome), stdin);
        printf("Carga Horaria: ");
        scanf("%d", &disciplinas[i].carga_horaria);
        getchar();

        printf("Professor Responsavel:\n");
        printf("Nome: ");
        fgets(disciplinas[i].professor_responsavel.nome, sizeof(disciplinas[i].professor_responsavel.nome), stdin);
    }

    int num_estudantes = 0;
    int disciplina_atual = 0;

    while (num_estudantes < MAX_ESTUDANTES && disciplina_atual < 2) {
        printf("Cadastro do Estudante %d\n", num_estudantes + 1);
        printf("Nome: ");
        fgets(estudantes[num_estudantes].nome, sizeof(estudantes[num_estudantes].nome), stdin);
        printf("Idade: ");
        scanf("%d", &estudantes[num_estudantes].idade);
        getchar();

        if (le_valida_idade(estudantes[num_estudantes].idade)) {
            num_estudantes++;

            if (num_estudantes % MAX_ESTUDANTES_POR_DISCIPLINA == 0) {
                disciplina_atual++;
            }
        } else {
            printf("Idade invalida. O estudante nao sera cadastrado.\n");
        }
    }

    printf("Relatorio de alunos matriculados na primeira disciplina ordenados por idade:\n");
    printf("Nome Professor\tNome Estudante\tIdade Estudante\n");

    bubble_sort(estudantes, num_estudantes);

    for (i = 0; i < num_estudantes && i < MAX_ESTUDANTES_POR_DISCIPLINA; i++) {
        printf("%s\t\t%s\t\t%d\n", disciplinas[0].professor_responsavel.nome, estudantes[i].nome, estudantes[i].idade);
    }

    printf("\nRelatorio de alunos matriculados na segunda disciplina ordenados por idade em ordem decrescente:\n");
    printf("Nome Professor\tNome Estudante\tIdade Estudante\n");

    bubble_sort(estudantes, num_estudantes);

    for (i = num_estudantes - 1; i >= 0 && i >= num_estudantes - MAX_ESTUDANTES_POR_DISCIPLINA; i--) {
        printf("%s\t\t%s\t\t%d\n", disciplinas[1].professor_responsavel.nome, estudantes[i].nome, estudantes[i].idade);
    }

    return 0;
}
