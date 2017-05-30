#include <jni.h>
#include <string>
#include <stdlib.h>

extern "C"

int cmpfunc (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

JNIEXPORT jstring JNICALL
Java_com_meoagency_android_codinggame_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jintArray JNICALL
Java_com_meoagency_android_codinggame_MainActivity_codingGame(JNIEnv *env, jobject instance,
                                                              jint participants, jint prix,
                                                              jintArray budgets_) {

    jint * arrayBudgets = env->GetIntArrayElements(budgets_, NULL);
    jintArray arrayParticipants = env->NewIntArray(participants);
    jint * arrayFinal = env->GetIntArrayElements(arrayParticipants, NULL);

    qsort(arrayBudgets, (size_t) participants, sizeof(int), cmpfunc);

    int total = 0;
    for (int i = 0; i < participants; ++i) {
        total += arrayBudgets[i];
    }

    if (total < prix) {
        return arrayParticipants;
    }

    int missingElement = participants;
    int rest = prix;
    for(int i = 0; i < participants; ++i){

        if(arrayBudgets[i] < rest/missingElement){
            jint toPay = arrayBudgets[i];
            arrayFinal[i] = toPay;
            rest -= toPay;
        } else {
            if ( missingElement == 1) {
                jint toPay = rest;
                arrayFinal[i] = toPay;
                rest -= toPay;
            }
            else {
                jint toPay = rest/missingElement - (rest % missingElement);
                arrayFinal[i] = toPay;
                rest -= toPay;
            }
        }
        missingElement--;
    }

    env->ReleaseIntArrayElements(arrayParticipants, arrayFinal, NULL);
    return arrayParticipants;
}