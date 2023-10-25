#include <iostream>
#include <cmath>

using namespace std;

double Ckn_calculate(int k, int n, int& depth);

int main()
{
    int k, n;
    int depth = 0;

    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;

    double C = Ckn_calculate(k, n, depth);

    cout << "C = " << C << endl;
    cout << "depth = " << depth << endl;

    return 0;
}



double Ckn_calculate(int k, int n, int& depth)
{
    double Ckn;

    if (k == n || k == 0)
    {
        Ckn = 1;
        return Ckn;
    }

    else
    {
        if (n > 0)
        {
            double Ckn1 = Ckn_calculate(k - 1, n - 1, depth);
            depth++;
            double Ckn2 = Ckn_calculate(k, n - 1, depth);
            depth++;

            Ckn = Ckn1 + Ckn2;

            return Ckn;
        }
        else
        {
            Ckn = tgamma(n) / (tgamma(k) * tgamma(n - k));
            depth++;
            return Ckn;

        }
    }
}