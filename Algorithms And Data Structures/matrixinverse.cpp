void inverse() {
    int i, j, k;
    float p, q;

    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++) {
            if(i == j)
                b[i][j]=1;
            else
                b[i][j]=0;
        }

    for(k = 0; k < 3; k++) {
        for(i = 0; i < 3; i++) {
            p = c[i][k];
            q = c[k][k];

            for(j = 0; j < 3; j++) {
                if(i != k) {
                    c[i][j] = c[i][j]*q - p*c[k][j];
                    b[i][j] = b[i][j]*q - p*b[k][j];
                }
            }
        }
    }

    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            b[i][j] = b[i][j] / c[i][i];

    printf("\n\nInverse Matrix is:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++)
            printf("%d ", b[i][j]);

        printf("\n");
    }
}
