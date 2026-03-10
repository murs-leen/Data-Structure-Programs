//#include <iostream>
//
//using namespace std;
//
//struct Job {
//    int JobID;
//    int Priority;      
//    int ArrivalTime;
//    int ExecutionTime;
//
//    Job() : JobID(0), Priority(0), ArrivalTime(0), ExecutionTime(0) {}
//
//    Job(int id, int p, int at, int et)
//        : JobID(id), Priority(p), ArrivalTime(at), ExecutionTime(et) {
//    }
//
//    void print() {
//        cout << "Job[ID:" << JobID << ", P:" << Priority << ", AT:" << ArrivalTime << ", ET:" << ExecutionTime << "]";
//    }
//};
//
//
//class JobScheduler {
//private:
//    Job* heapArray;  
//    int capacity;     
//    int heapSize;     
//
//
//    int parent(int i) { return (i - 1) / 2; }
//
//    int left(int i) { return (2 * i) + 1; }
//
//    int right(int i) { return (2 * i) + 2; }
//
//    void swap(Job& a, Job& b) {
//        Job temp = a;
//        a = b;
//        b = temp;
//    }
//
//    bool hasHigherPriority(Job a, Job b) {
//        if (a.Priority < b.Priority) {
//            return true;
//        }
//        if (a.Priority == b.Priority) {
//            if (a.ArrivalTime < b.ArrivalTime) {
//                return true;
//            }
//        }
//        return false;
//    }
//
//    void heapifyUp(int index) {
//        if (index > 0 && hasHigherPriority(heapArray[index], heapArray[parent(index)])) {
//    
//            swap(heapArray[index], heapArray[parent(index)]);
//
//            heapifyUp(parent(index));
//        }
//    }
//
//    void heapifyDown(int index) {
//        int l = left(index);
//        int r = right(index);
//        int smallest = index; 
//        if (l < heapSize && hasHigherPriority(heapArray[l], heapArray[smallest])) {
//            smallest = l;
//        }
//        if (r < heapSize && hasHigherPriority(heapArray[r], heapArray[smallest])) {
//            smallest = r;
//        }
//
//        if (smallest != index) {
//            swap(heapArray[index], heapArray[smallest]);
//
//            heapifyDown(smallest);
//        }
//    }
//
//    void resize() {
//        cout << "   -> DEBUG: Heap full. Resizing capacity from " << capacity << " to " << capacity * 2 << endl;
//        int newCapacity = capacity * 2;
//        Job* newArray = new Job[newCapacity];
//
//        for (int i = 0; i < heapSize; i++) {
//            newArray[i] = heapArray[i];
//        }
//
//        delete[] heapArray;
//        heapArray = newArray;
//        capacity = newCapacity;
//    }
//    int findJobIndex(int jobID) {
//        for (int i = 0; i < heapSize; i++) {
//            if (heapArray[i].JobID == jobID) {
//                return i;
//            }
//        }
//        return -1; // Nahi mila
//    }
//
//
//public:
//    // --- CONSTRUCTOR & DESTRUCTOR ---
//    JobScheduler(int cap) {
//        capacity = cap;
//        heapSize = 0;
//        heapArray = new Job[capacity];
//        cout << "JobScheduler (Min-Heap) initialized with capacity " << capacity << "." << endl;
//    }
//
//    ~JobScheduler() {
//        delete[] heapArray;
//        cout << "JobScheduler destroyed." << endl;
//    }
//
//    void insertJob(Job newJob) {
//        cout << "\n--- Operation: 1. Insert Job (ID: " << newJob.JobID << ") ---" << endl;
//        if (heapSize == capacity) {
//            resize();
//        }
//        heapArray[heapSize] = newJob;
//        int currentIndex = heapSize;
//        heapSize++;
//
//        heapifyUp(currentIndex);
//
//        cout << "Job inserted. New heap size: " << heapSize << endl;
//        cout << "Analysis: Time Complexity: O(log n) (Amortized O(1) if no resize)" << endl;
//    }
//
//    Job extractHighestPriorityJob() {
//        cout << "\n--- Operation: 2. Extract Highest Priority Job ---" << endl;
//        if (heapSize == 0) {
//            throw "Exception: Cannot extract from an empty heap.";
//        }
//
//        // Root (sab se high-priority) ko save karein
//        Job root = heapArray[0];
//
//        // Akhri element ko root par lay aayein
//        heapArray[0] = heapArray[heapSize - 1];
//        heapSize--;
//
//        // Heap property ko restore karein (Heapify Down)
//        if (heapSize > 0) {
//            heapifyDown(0);
//        }
//
//        cout << "Job extracted. New heap size: " << heapSize << endl;
//        cout << "Analysis: Time Complexity: O(log n)" << endl;
//        return root;
//    }
//
//    // --- 3. INCREASE/DECREASE PRIORITY ---
//    void changePriority(int jobID, int newPriority) {
//        cout << "\n--- Operation: 3. Change Priority (ID: " << jobID << ") ---" << endl;
//
//        int index = findJobIndex(jobID);
//        if (index == -1) {
//            throw "Exception: Job ID not found for priority change.";
//        }
//
//        int oldPriority = heapArray[index].Priority;
//        heapArray[index].Priority = newPriority;
//
//        // Check karein ke priority behtar hui ya kharab
//        if (newPriority < oldPriority) {
//            // Priority behtar hui (number chota hua), tou Heapify UP
//            heapifyUp(index);
//        }
//        else {
//            // Priority kharab hui (number bara hua), tou Heapify DOWN
//            heapifyDown(index);
//        }
//
//        cout << "Priority for Job " << jobID << " changed from " << oldPriority << " to " << newPriority << endl;
//        cout << "Analysis: Time Complexity: O(n) [find] + O(log n) [heapify] = O(n)" << endl;
//    }
//
//    // --- 4. DELETE SPECIFIC JOB ---
//    void deleteSpecificJob(int jobID) {
//        cout << "\n--- Operation: 4. Delete Specific Job (ID: " << jobID << ") ---" << endl;
//
//        int index = findJobIndex(jobID);
//        if (index == -1) {
//            throw "Exception: Job ID not found for deletion.";
//        }
//
//        // Agar akhri element hai tou simple delete karein
//        if (index == heapSize - 1) {
//            heapSize--;
//            cout << "Job (last element) deleted." << endl;
//            cout << "Analysis: Time Complexity: O(n) [find] = O(n)" << endl;
//            return;
//        }
//
//        // Job ko akhri element se swap karein
//        swap(heapArray[index], heapArray[heapSize - 1]);
//        heapSize--; // "Delete" karein
//
//        // Ab 'index' par jo naya (neeche se aaya hua) element hai,
//        // usay uski sahi jagah pohnchayein.
//        // Hamein nahi pata usay upar jana hai ya neechay.
//        // Hum check karte hain: kya woh apne parent se behtar hai?
//        if (index > 0 && hasHigherPriority(heapArray[index], heapArray[parent(index)])) {
//            heapifyUp(index); // Tou upar bhejein
//        }
//        else {
//            heapifyDown(index); // Warna neechay bhejein
//        }
//
//        cout << "Job " << jobID << " deleted." << endl;
//        cout << "Analysis: Time Complexity: O(n) [find] + O(log n) [heapify] = O(n)" << endl;
//    }
//
//    // --- 5. MERGE TWO HEAPS ---
//    void mergeTwoHeaps(JobScheduler& otherHeap) {
//        cout << "\n--- Operation: 5. Merge Two Heaps ---" << endl;
//
//        int otherSize = otherHeap.heapSize;
//        if (otherSize == 0) {
//            cout << "Other heap is empty. Nothing to merge." << endl;
//            return;
//        }
//
//        // Har job ko doosray heap se nikaal kar is heap mein insert karein
//        // Yeh O(k * log(n+k)) hai.
//        for (int i = 0; i < otherSize; i++) {
//            // Simple insert logic (resize check ke sath)
//            if (heapSize == capacity) {
//                resize();
//            }
//            heapArray[heapSize] = otherHeap.heapArray[i];
//            heapifyUp(heapSize); // Naye element ko uski jagah pohnchayein
//            heapSize++;
//        }
//
//        // Doosray heap ko khali kar dein
//        otherHeap.heapSize = 0;
//
//        cout << otherSize << " jobs merged. New heap size: " << heapSize << endl;
//        cout << "Analysis: Time Complexity: O(k * log(n+k))" << endl;
//    }
//
//    // --- 6. DISPLAY HEAP STATE (LEVEL-WISE) ---
//    void displayHeapState() {
//        cout << "\n--- Operation: 6. Display Heap State (Level-wise) ---" << endl;
//
//        if (heapSize == 0) {
//            cout << "[ Heap is Empty ]" << endl;
//            cout << "Analysis: Time Complexity: O(1)" << endl;
//            return;
//        }
//
//        int elementsInLevel = 1;
//        int elementsPrinted = 0;
//
//        cout << "Heap (Size: " << heapSize << ", Capacity: " << capacity << ")" << endl;
//        cout << "------------------------------------------" << endl;
//
//        for (int i = 0; i < heapSize; i++) {
//            Job& j = heapArray[i];
//            cout << "[ID:" << j.JobID << " P:" << j.Priority << " AT:" << j.ArrivalTime << "] ";
//
//            elementsPrinted++;
//
//            // Jab is level ke tamam elements print ho jayein
//            if (elementsPrinted == elementsInLevel) {
//                cout << endl; // Agli line par jayein
//                elementsInLevel *= 2; // Agli level mein double elements hongay
//                elementsPrinted = 0;  // Counter reset karein
//            }
//        }
//        cout << "\n------------------------------------------" << endl;
//        cout << "Analysis: Time Complexity: O(n)" << endl;
//    }
//};
//
//
//int main() {
//    try {
//        JobScheduler scheduler(5); // 5 ki capacity se shuru
//
//        scheduler.insertJob(Job(1, 5, 10, 20)); 
//        scheduler.insertJob(Job(2, 3, 12, 10)); // P:3, AT:12
//        scheduler.insertJob(Job(3, 5, 8, 5)); 
//        scheduler.insertJob(Job(4, 1, 20, 30)); 
//        scheduler.insertJob(Job(5, 3, 15, 10));
//
//        scheduler.displayHeapState();
//
//        Job topJob = scheduler.extractHighestPriorityJob();
//        cout << ">> Extracted Job: ";
//        topJob.print();
//        cout << endl;
//
//        scheduler.displayHeapState();
//        scheduler.changePriority(1, 2);
//        scheduler.displayHeapState();
//
//        scheduler.deleteSpecificJob(3); 
//        scheduler.displayHeapState();
//
//        // 7. Doosra heap banayein aur merge karein
//        JobScheduler scheduler2(3);
//        scheduler2.insertJob(Job(10, 8, 1, 1));
//        scheduler2.insertJob(Job(11, 2, 5, 5)); // Yeh Job 1 se bhi high priority hai
//
//        cout << "\n\n*** MERGING HEAPS ***" << endl;
//        scheduler.mergeTwoHeaps(scheduler2);
//        scheduler.displayHeapState();
//        // Expected new root: Job 11 (P:2, AT:5)
//
//        // 8. Exception test karein
//        cout << "\n\n*** TESTING EXCEPTION ***" << endl;
//        scheduler.deleteSpecificJob(999); // Yeh job mojood nahi
//
//    }
//    catch (const char* msg) {
//        // Exception ko pakrein
//        cerr << "\n!!! EXCEPTION CAUGHT !!!" << endl;
//        cerr << "Error: " << msg << endl;
//    }
//
//    return 0;
//}