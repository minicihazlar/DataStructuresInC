// Greatest common divisor
int general_gcd(int x, int y)
{
    if (y == 0)
    {
        return x;
    }
    else
    {
        general_gcd(y, x % y);
    }
    return 0;
}

// Square root 
double general_sqrt(int val)
{
    double i = val / 2;
    double past = 0;

    if (val == 1) return 1;
    while (1)
    {
        i = (i + (val / i)) / 2;
        if (i == past) break;
        past = i;
    }
    return i;
}
