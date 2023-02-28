#include <jni.h> 

#include <math.h>

#include <iostream> 
#include <omp.h>
#include "Week8.h" 

using namespace std;

JNIEXPORT jdouble JNICALL Java_Week8_calculateSTDDev(JNIEnv* env, jobject thisObj, jintArray inJNIArray) {

	jdouble mean = Java_Week8_calculateMean(env, thisObj, inJNIArray);

	jint* myArray = env->GetIntArrayElements(inJNIArray, NULL);

	jsize length = env->GetArrayLength(inJNIArray);

	jdouble aux = 0.0;

	

#pragma omp parallel
	{
	jdouble aux2 = omp_get_thread_num();
	cout << "thread number :" << aux2 << " is working" << endl;

#pragma omp barrier
	}


#pragma omp parallel for reduction(+:aux)
	for (int i = 0; i < length; ++i) {

		aux += pow((double)myArray[i] - mean, 2);
	}
#pragma omp barrier
	env->ReleaseIntArrayElements(inJNIArray, myArray, 0); 

	jdouble standardDev = sqrt(aux / length);

	return standardDev;

}

JNIEXPORT jdouble JNICALL Java_Week8_calculateMean(JNIEnv* env, jobject thisObj, jintArray inJNIArray) {

	jint* myArray = env->GetIntArrayElements(inJNIArray, NULL);

	int i =0;

	jsize length = env->GetArrayLength(inJNIArray);

	jdouble sum = 0;

#pragma omp parallel for reduction(+:sum)
	for (i = 0; i < length; i++) {

		sum += myArray[i];

	}
#pragma omp barrier
	jdouble mean = sum / length;

	env->ReleaseIntArrayElements(inJNIArray, myArray, 0); 

	return mean;

}