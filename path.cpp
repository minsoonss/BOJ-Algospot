#include <cstdio>
#include <stack>
using namespace std;

int main(void)
{
	FILE *in, *out;
	
	in = fopen("path.inp", "r");
	out = fopen("path.out", "w");

	char k;
	while(!feof(in))
	{
		fscanf(in, "%c", &k);
		fprintf(stderr, "%c", k);
	}

	return 0;
}