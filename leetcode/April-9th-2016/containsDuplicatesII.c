#include <string.h>
#include <math.h>

struct bucket {
    int value;
    int index;
    struct bucket* next;
};

int containsNearbyDuplicate(int* nums, int numsSize, int k) 
{
    struct bucket** htable = (struct bucket**)calloc(numsSize, sizeof(struct bucket*));
    if (!htable) return 0;

    struct bucket* buckets = (struct bucket*)calloc(numsSize * numsSize, sizeof(struct bucket));
    if (!buckets) return 0;
    
    int count = 0;    
    int num = 0;
    struct bucket* pbucket = NULL;
    for (int i = 0; i < numsSize; ++i) 
    {
        num = nums[i];
        pbucket = htable[abs(num) % numsSize];
        if (!pbucket) {
            // allocate a bucket
            // oh wait... we've already done that!
            htable[abs(num) % numsSize] = &buckets[count];        
            pbucket = &buckets[count];
            pbucket->value = num;
            pbucket->index = i;
            ++count;
        } else {
            // collision occured here
            // our value could still be sitting in the chain
            // so check for that as we go
            while (1) {                
                if (pbucket->value == num) {
                    if (i - pbucket->index <= k) {
                        return 1;
                    }
                    pbucket->index = i;

                    break;
                }
                if (!pbucket->next) {
                    pbucket->next = &buckets[count];                    

                    pbucket = pbucket->next;
                    pbucket->value = num;
                    pbucket->index = i;

                    ++count;

                    break;
                }
                pbucket = pbucket->next;
            }
        }        
    }
    free(buckets);
    free(htable);
    return 0;
}
