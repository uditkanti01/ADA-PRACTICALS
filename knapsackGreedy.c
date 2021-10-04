#include <stdio.h>
#include <stdlib.h>

struct Object {
    int value;
    int weight;
    float ratio;
};

int SolvingKnapsack(struct Object object[], int total_objects, int total_weight) {
    int current_weight = 0;
    float final_value = 0;
    for (int i = 0; i < total_objects; i++) {
        if(current_weight + object[i].weight <= total_weight) {
            final_value = final_value + object[i].value;
            current_weight = current_weight + object[i].weight;
        }
        else {
            final_value = final_value + (float)((total_weight - current_weight)*object[i].value)/(float)object[i].weight;
            break;
        }
    }
    return final_value;
}

int main(void) {
    int total_weight, total_objects;

    printf("Enter Total Number of Objects: ");
    scanf("%d", &total_objects);

    printf("Enter Maximum Allowed Weight: ");
    scanf("%d", &total_weight);

    struct Object object[total_objects];  

    for (int i = 0; i < total_objects; i++) {
        printf("Enter Value of Object %d: ", i+1);
        scanf("%d", &object[i].value);

        printf("Enter Weight of Object %d: ", i+1);
        scanf("%d", &object[i].weight);

        object[i].ratio = (float)object[i].value/(float)object[i].weight;
    } 

	for (int i = 0; i < total_objects; i++) {
		int flag = 0;
		for (int j = 0; j < total_objects - 1; j++) {
			if (object[j].value < object[j + 1].value) {
				struct Object temp = object[j];
				object[j] = object[j + 1];
				object[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0) {
			break;
		}
	}   

    float ans = SolvingKnapsack(object, total_objects, total_weight);

    printf("\nBy Decreasing Value order the maximum Value is %f\n",ans);

    for (int i = 0; i < total_objects; i++) {
		int flag = 0;
		for (int j = 0; j < total_objects - 1; j++) {
			if (object[j].weight > object[j + 1].weight) {
				struct Object temp = object[j];
				object[j] = object[j + 1];
				object[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0) {
			break;
		}
	}   

    ans = SolvingKnapsack(object, total_objects, total_weight);

    printf("\nBy Increasing Weight order the maximum Value is %f\n",ans);

    for (int i = 0; i < total_objects; i++) {
		int flag = 0;
		for (int j = 0; j < total_objects - 1; j++) {
			if (object[j].ratio < object[j + 1].ratio) {
				struct Object temp = object[j];
				object[j] = object[j + 1];
				object[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0) {
			break;
		}
	}   

    ans = SolvingKnapsack(object, total_objects, total_weight);

    printf("\nBy Decreasing Ratio order the maximum Value is %f\n",ans);

    return 0;
}
