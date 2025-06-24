int sumwhilepos(int x, int y)
{
    int res = 0;
    while (x > 0)
    {
        if (y > 0)
        {
            res += x;
            y--;
        }
        x--;
    }
    return res;
}