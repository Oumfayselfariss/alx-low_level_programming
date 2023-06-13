#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define ELF_MAGIC_SIZE 4

typedef struct {
    unsigned char e_ident[ELF_MAGIC_SIZE];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    uint64_t e_entry;
    uint64_t e_phoff;
    uint64_t e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
} Elf64_Ehdr;

void print_error(const char *error_message) {
    fprintf(stderr, "Error: %s\n", error_message);
}

void print_elf_header_info(Elf64_Ehdr *header) {
    printf("Magic:  ");
    for (int i = 0; i < ELF_MAGIC_SIZE; i++) {
        printf("%02x ", header->e_ident[i]);
    }
    printf("\n");

    printf("Class:  ");
    switch (header->e_ident[4]) {
        case 1:
            printf("ELF32\n");
            break;
        case 2:
            printf("ELF64\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }

    printf("Data:  ");
    switch (header->e_ident[5]) {
        case 1:
            printf("2's complement, little-endian\n");
            break;
        case 2:
            printf("2's complement, big-endian\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }

    printf("Version:  %d\n", header->e_ident[6]);

    printf("OS/ABI:  ");
    switch (header->e_ident[7]) {
        case 0:
            printf("System V\n");
            break;
        case 1:
            printf("HP-UX\n");
            break;
        case 2:
            printf("NetBSD\n");
            break;
        case 3:
            printf("Linux\n");
            break;
        case 6:
            printf("Solaris\n");
            break;
        case 7:
            printf("AIX\n");
            break;
        case 8:
            printf("IRIX\n");
            break;
        case 9:
            printf("FreeBSD\n");
            break;
        case 10:
            printf("Tru64\n");
            break;
        case 11:
            printf("Novell Modesto\n");
            break;
        case 12:
            printf("OpenBSD\n");
            break;
        case 13:
            printf("OpenVMS\n");
            break;
        case 14:
            printf("NonStop Kernel\n");
            break;
        case 15:
            printf("AROS\n");
            break;
        case 16:
            printf("Fenix OS\n");
            break;
        case 17:
            printf("CloudABI\n");
            break;
        case 18:
            printf("OpenVOS\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }

    printf("ABI Version:  %d\n", header->e_ident[8]);

    printf("Type:  %u\n", header->e_type);

   

