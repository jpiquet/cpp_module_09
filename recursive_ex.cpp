#include <iostream>

// void compte_rebour(int n)
// {
// 	if (n == 0)
// 		return;
// 	else
// 	{
// 		std::cout << n << '\n';
// 		compte_rebour(n - 1);
// 	}
// }

// int	somme(int a[], int i)
// {
// 	if(i == 0)
// 		return a[i];

// 	int res = a[i] + somme(a, i - 1);
// 	return res;
// }

// int	max(int a[], int i)
// {
// 	if(i == 0)
// 		return a[i];

// 	int res;
// 	if (a[i] > max(a, i - 1))
// 		res = a[i];
// 	else
// 		res = max(a, i - 1);
// 	return res;
// }

int compter(int a[], int n, int i, int compteur)
{
	if (i == 0)
		return a[i];
	if ()
	{
		std::cout << "hello" << '\n';
		compteur++;
	}
	compter(a, n, i - 1, compteur);
	return compteur;
}

int main()
{
	// compte_rebour(5);

	int	a[5] = {1, 2, 1, 4, 1};
	int i = 4;

	int compteur = 0;
	std::cout << compter(a, 1, i, compteur);

	return 0;
}
