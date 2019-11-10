#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double angle,normalizer;
    scanf("%lf",&angle);
    normalizer=M_PI / 180;
    printf("Sine:%lf\n",sin(angle*normalizer));
    printf("Cosine:%lf\n",cos(angle*normalizer));
    printf("Tangent:%lf",tan(angle*normalizer));
    return 0;
}
