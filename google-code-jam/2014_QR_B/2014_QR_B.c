#include <stdio.h>

int main(void) {
	int i, k, j, T;
	scanf("%d\n", &T);

	for (i=0; i<T; i++) {
		double cost, extra, target;
		scanf("%lf %lf %lf\n", &cost, &extra, &target);
		double time = 0, prevTime = 0;
		double upgrades = 0;

		while ( (time < prevTime) || (prevTime == 0) ) {
			// Initialize
			double cookieRate = 2;
			prevTime = time;
			time = 0;

			cookieRate = 2 + upgrades*extra;
			upTime += cost/cookieRate;

			// After enough upgrades, go all the way
			time += target/cookieRate;

//			printf("With %lf upgrades, time is %lf.\n\n", upgrades, time);

			// ++number of upgrades to see if time improves
			upgrades++;
		}
		printf("Case #%d: %0.7f\n", i+1, prevTime);
			 
	}
		
	return 0;
}
