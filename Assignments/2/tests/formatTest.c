#include <stdio.h>
#include <stdlib.h>

int main() {
	char desc[31] = "Handy Hoozit";
	char id[16] = "928352";
	short qty = 42;

	printf("  %-32s%-9s%s\n", "DESC", "QTY", "ID");
	for (size_t i = 0; i < 30; i++) printf("-");
	printf("  -------  ");
	for (size_t i = 0; i < 15; i++) printf("-");
	printf("\n");

	printf("%-30s   %5hi    %s\n", "Handy Hoozit", 42, "928352");
	printf("%s%39hi%40s\n", "Dull Fragile Doodad", 4, "DDE");

	return 0;
}

