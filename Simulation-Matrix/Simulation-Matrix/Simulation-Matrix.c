#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Source.h"

#pragma warning(disable : 4996)

int main()
{
	system("COLOR 0A");
	// Main Declaretions
	float _weight, _bias, _organism = 0;
	printf("Enter organism count (O): ");
	scanf("%f", &_organism);
	float *outputs = (float *)malloc((_length * _organism) * sizeof(float));
	float *_input = (float *)malloc((_length * _organism) * sizeof(float));
	float *_outputs = (float *)malloc((_length * _organism) * sizeof(float));
	char array[_array_length * 2];
	int position = _array_length / 2;
	srand((unsigned int)time(NULL));
	// MATRIX AREA
	for (int i = 0; i < _array_length * 2; i++) {
		array[i] = '.';
	}
	array[position] = 'O';
	printf("Enter weight (W): ");
	scanf("%f", &_weight);
	printf("Enter bias (B): ");
	scanf("%f", &_bias);
	// RANDOM INPUTS
	for (int i = 0; i < _length * _organism; i++) {
		_input[i] = (float)rand() / RAND_MAX * 2.0f - 1.0f;
	}
	// CREATE A ORGANISM
	for (int count = 0; count < _organism; count++)
	{
		organism(_input + _length * count, _weight, _bias, _outputs + _length * count, outputs + _length * count);
	}
	// MEMORY CONTROL
	if (_input == NULL || _outputs == NULL || outputs == NULL) {
		printf(" Memory allocation failed\n");
		_sleep(2000);
		return 1;
	}
	else
	{
		// MATRIX MAIN CODE
		printf("\n AI Trained. Simulation started...\n");
		_sleep(2000);
		system("cls");
		for (int i = 0; i < _length * _organism; i++) {
			for (int j = 0; j < _organism; j++) {
				_move(array, _array_length * 2, &position, outputs[j * _length + i]);
				for (int k = 0; k < _array_length * 2; k++) {
					printf("%c", array[k]);
				}
				printf("\n");
			}

			for (int _counter = 0; _counter < _organism; _counter++) {
				printf("%d. Organism Output: %f\n", _counter, outputs[_counter * _length + i]);
			}

			_sleep(500);
			system("cls");
		}
		free(outputs);
		free(_input);
		free(_outputs);
	}
	return 0;
}
