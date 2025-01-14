    double res = 0;
    for (int i = 0; i < 100; i++)
    {
        double m = (r + l) / 2;

        if (good(m, values))
        {
            res = m;
            r = m;
        }
        else
        {
            l = m;
        }
    }

    cout << setprecision(10);

    cout << res << endl;
}
