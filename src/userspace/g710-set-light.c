#include <stdio.h>
	
int main (int argc, char** argv) {

	if (argc != 3) {
		printf("You need to call this script with:\n");
		printf("\tg710-set-light WASD_value OTHER_value\n");
		return -1;
	}

	int wasd  = atoi(argv[1]);
	int other = atoi(argv[2]);

	if (wasd < 0 || other < 0 || wasd > 4 || other > 4) {
		printf("Only values 0-4 are accepted.\n");
		return -2;
	}

	int light_value = wasd << 4 | other;

	#ifdef DEBUG
	printf("Setting LEDs to: %d\n", light_value);
	#endif

	FILE *file;
	file = fopen("/sys/bus/hid/devices/0003:046D:C24D.0002/logitech-g710/led_keys","w");
	fprintf(file,"%d",light_value);
	fclose(file);

	return 0;
}
