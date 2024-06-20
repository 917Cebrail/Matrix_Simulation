#ifndef SOURCE_H
#define SOURCE_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define _length 40
#define _array_length 40

extern float sigmoid(float input, float weight, float bias)
{
	return 1 / (1 + exp(-((weight * input) + bias)));
}

extern float relu(float input)
{
	if (input <=0)
	{
		return 0;
	}
	else
	{
		return input;
	}
}

void softmax(float inputs[], int num_inputs, float outputs[]) {
	float max_val = inputs[0];
	float sum = 0.0;
	for (int i = 1; i < num_inputs; ++i) {
		if (inputs[i] > max_val) {
			max_val = inputs[i];
		}
	}
	for (int i = 0; i < num_inputs; ++i) {
		outputs[i] = exp(inputs[i] - max_val);
		sum += outputs[i];
	}
	for (int i = 0; i < num_inputs; ++i) {
		outputs[i] /= sum;
	}
}

int hide_neuron(float _input, float _weight, float _bias)
{
	float w, b;
	float result;
	int res;
	w = 0; b = 0;
	result = sigmoid(_input, _weight, _bias);
	// printf(" [W] : %f | [B] : %f | [I] : %f\n", _weight, _bias, _input);
	// printf(" [R] : %f\n", result);
	if (fabs(result - 1.0) < 0.000001)
	{
		res = 1;
		// printf(" Result : %d\n", res);
	}
	else
	{
		for (int j = 0; j < _length; j++)
		{
			result = sigmoid(_input, _weight + j, _bias + j);
			// printf(" %d. Attempt -> [R] : %f\n", j, result);
			if (fabs(result - 1.0) < 0.000001)
			{
				res = 1;
				// printf(" Result : %d\n", res);
				w = _weight + j;
				b = _bias - j;
				break;
			}
			else
			{
				res = 0;
				// printf(" Result : %d\n", res);
			}
		}
	}
	return res;
}

void organism(float _input[_length], float _weight, float _bias, float _outputs[_length], float outputs[_length])
{
	for (int i = 0; i < _length; i++) {
		_input[i] = rand() % 5;
	}
	for (int k = 0; k < _length; k++) {
		_outputs[k] = hide_neuron(_input[k], _weight, _bias);
	}

	float hidden_input[_length];
	for (int i = 0; i < _length; i++) {
		hidden_input[i] = (_outputs[i] + _input[i]) / 2.0;
	}
	softmax(hidden_input, _length, outputs);
	// outputs : Move outputs
}

void _move(char array[], int length, int *position, float direction) {
	int move_direction = 0;
	if (direction <= 0.0490)
	{
		move_direction = 1;
	}
	else if (direction > 0.0500 && direction <= 0.0900) 
	{
		move_direction = -1;
	}
	else
	{
		if (direction < -1.0)
		{
			move_direction = -1;
		}
		else if (direction > 1.0)
		{
			move_direction = 1;
		}
		else
		{
			move_direction = direction;
		}
	}

	int new_position = *position + move_direction;

	if (new_position >= 0 && new_position < length) {
		array[*position] = '.';
		array[new_position] = 'O';
		*position = new_position;
	}
}

#endif // !Source.h
