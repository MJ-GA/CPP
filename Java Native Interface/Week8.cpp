#include <jni.h> 

#include <math.h>

#include <iostream> 

#include "Week8.h" 

using namespace std;

JNIEXPORT jdouble JNICALL Java_Week8_calculateSTDDev(JNIEnv* env, jobject thisObj, jintArray inJNIArray) {

	jdouble mean = Java_Week8_calculateMean(env, thisObj, inJNIArray);

	jint* myArray = env->GetIntArrayElements(inJNIArray, NULL);

	jsize length = env->GetArrayLength(inJNIArray);

	jdouble aux = 0.0;

	for (int i = 0; i < length; ++i)

		aux += pow((double)myArray[i] - mean, 2);

	env->ReleaseIntArrayElements(inJNIArray, myArray, 0); 

	jdouble standardDev = sqrt(aux / length);

	return standardDev;

}

JNIEXPORT jdouble JNICALL Java_Week8_calculateMean(JNIEnv* env, jobject thisObj, jintArray inJNIArray) {

	jint* myArray = env->GetIntArrayElements(inJNIArray, NULL);

	int i =0;

	jsize length = env->GetArrayLength(inJNIArray);

	jdouble sum = 0;

	for (i = 0; i < length; i++) {

		sum += myArray[i];

	}
	jdouble mean = sum / length;

	env->ReleaseIntArrayElements(inJNIArray, myArray, 0); 

	return mean;

}