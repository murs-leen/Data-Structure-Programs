//﻿/*Algorithm
//
//1. Ek stack of integers bana lena he.
//
//2. Postfix expression ke har character ko read karna he:
//
//        Agar digit ho → usko int me convert karke stack me daalo.
//
//        Agar operator ho → stack se do numbers nikalo (val1, val2) aur operation perform karke result ko wapas stack me daalo.
//
//3. End me stack ke top pe jo value hogi wahi final result hai.
//
//*/
//
//
//
//#include <iostream>
//#include <stack>
//#include <string>
//#include <cmath>
//using namespace std;
//
//// Postfix expression evaluate karna
//int evaluatePostfix(string s) {
//    stack<int> st;
//    for (char c : s) {
//        if (isdigit(c)) {
//            // agar number ho to stack me daal do
//            st.push(c - '0'); // char se int me convert
//        }
//        else {
//            // agar operator ho to do numbers nikaal ke operation karo
//            int val2 = st.top(); st.pop();
//            int val1 = st.top(); st.pop();
//
//            switch (c) {
//            case '+': st.push(val1 + val2); break;
//            case '-': st.push(val1 - val2); break;
//            case '*': st.push(val1 * val2); break;
//            case '/': st.push(val1 / val2); break;
//            case '^': st.push(pow(val1, val2)); break;
//            }
//        }
//    }
//    return st.top(); // final result
//}
//
//int main() {
//    string postfix = "231*+"; // 2+(3*1)
//    cout << "Postfix Expression: " << postfix << endl;
//    cout << "Evaluation Result: " << evaluatePostfix(postfix) << endl;
//    return 0;
//}