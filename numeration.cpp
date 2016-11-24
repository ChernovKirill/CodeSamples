UnitTG unitsG[unitsNum+1];
const double step3m[3] = {1.,sqrt(3.)/2.,.5};
const int ShiftsNum = 2+6;
const double shifts3[ShiftsNum][3] = {{1.,0.,0.},{0.,1.,1.},{0.,1.,-1.},{-1.,0.,0.},{0.,-1.,-1.},{0.,-1.,1.},{1.,0.,0.},{0.,1.,1.}};
const int RowNum = 6+1;

i=1;
unitsG[i].x = 0.;
unitsG[i].y = 0.;
int rCount = 0;
for (int j = 1; j <= RowNum; j++) {
    i++;
    unitsG[i].x = unitsG[i-1].x + step * step3m[1] * shifts3[0][1];
    unitsG[i].y = unitsG[i-1].y + step * (step3m[0] * shifts3[0][0] + step3m[2] * shifts3[0][2]);
    unitsG[i].x += rCount == 0 ? 0. : 1. * step * step3m[1] * shifts3[1][1];
    unitsG[i].y += rCount == 0 ? 0. : 1. * step * (step3m[0] * shifts3[1][0] + step3m[2] * shifts3[1][2]);
    rCount++;
    int k;
    for (k = 2; k < ShiftsNum - 1; k++) {
        for (int l = 0; l < rCount; l++) {
            i++;
            unitsG[i].x = unitsG[i-1].x + step * step3m[1] * shifts3[k][1];
            unitsG[i].y = unitsG[i-1].y + step * (step3m[0] * shifts3[k][0] + step3m[2] * shifts3[k][2]);
        }
    }
    for (int l = 0; l < rCount - 1; l++) {
        i++;
        unitsG[i].x = unitsG[i-1].x + step * step3m[1] * shifts3[k][1];
        unitsG[i].y = unitsG[i-1].y + step * (step3m[0] * shifts3[k][0] + step3m[2] * shifts3[k][2]);
    }
}
