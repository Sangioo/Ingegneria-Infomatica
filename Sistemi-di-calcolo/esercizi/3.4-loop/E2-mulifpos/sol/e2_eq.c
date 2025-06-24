int sumwhilepos(int x, int y)
{
    int a = 0, c = x, d = y;
L:
    if (c <= 0)
        goto E;
    if (d <= 0)
        goto F;

    a += c;
    d--;

F:
    c--;
    goto L;

E:
    return a;
}