//#include <iostream>
//#include <string>
//using namespace std;
//
//class Node {
//public:
//    string data;
//    Node* next;
//    Node(string val) {
//        data = val;
//        next = nullptr;
//    }
//};
//
//class Stack {
//    Node* head;
//public:
//    Stack() {
//        head = nullptr;
//    }
//    void push(string val) {
//        Node* temp = new Node(val);
//        temp->next = head;
//        head = temp;
//    }
//    void pop() {
//        if (head == nullptr) return;
//        Node* temp = head;
//        head = head->next;
//        delete temp;
//    }
//    string top() {
//        return head ? head->data : "";
//    }
//    bool empty() {
//        return head == nullptr;
//    }
//    void show() {
//        cout << "Stack: ";
//        Node* temp = head;
//        while (temp) {
//            cout << temp->data << " ";
//            temp = temp->next;
//        }
//        cout << endl;
//    }
//};
//
//int prec(string op) {
//    if (op == "+" || op == "-") return 1;
//    if (op == "*" || op == "/" || op == "%") return 2;
//    return 0;
//}
//
//bool isOp(string t) {
//    return (t == "+" || t == "-" || t == "*" || t == "/" || t == "%");
//}
//
//void split(string expr, string arr[], int& size) {
//    size = 0;
//    string temp = "";
//    for (char c : expr) {
//        if (c == ' ') {
//            if (!temp.empty()) {
//                arr[size++] = temp;
//                temp = "";
//            }
//        }
//        else temp += c;
//    }
//    if (!temp.empty()) arr[size++] = temp;
//}
//
//string infixToPostfix(string expr) {
//    Stack s;
//    string output = "";
//    string tokens[100];
//    int n;
//    split(expr, tokens, n);
//    for (int i = 0; i < n; i++) {
//        string t = tokens[i];
//        if (!isOp(t) && t != "(" && t != ")") output += t + " ";
//        else if (t == "(") s.push(t);
//        else if (t == ")") {
//            while (!s.empty() && s.top() != "(") {
//                output += s.top() + " ";
//                s.pop();
//            }
//            if (!s.empty()) s.pop();
//        }
//        else {
//            while (!s.empty() && prec(t) <= prec(s.top())) {
//                output += s.top() + " ";
//                s.pop();
//            }
//            s.push(t);
//        }
//        s.show();
//        cout << "Result: " << output << endl;
//    }
//    while (!s.empty()) {
//        output += s.top() + " ";
//        s.pop();
//        s.show();
//        cout << "Result: " << output << endl;
//    }
//    return output;
//}
//
//string infixToPrefix(string expr) {
//    string t[100]; int n;
//    split(expr, t, n);
//    string rev[100];
//    for (int i = 0; i < n; i++) rev[i] = t[n - i - 1];
//    for (int i = 0; i < n; i++) {
//        if (rev[i] == "(") rev[i] = ")";
//        else if (rev[i] == ")") rev[i] = "(";
//    }
//    string revExpr = "";
//    for (int i = 0; i < n; i++) revExpr += rev[i] + " ";
//    string post = infixToPostfix(revExpr);
//    string pt[100]; int m;
//    split(post, pt, m);
//    string prefix = "";
//    for (int i = m - 1; i >= 0; i--) prefix += pt[i] + " ";
//    return prefix;
//}
//
//int evalPostfix(string exp) {
//    Stack s;
//    string t[100]; int n;
//    split(exp, t, n);
//    for (int i = 0; i < n; i++) {
//        string tk = t[i];
//        if (!isOp(tk)) s.push(tk);
//        else {
//            int b = stoi(s.top()); s.pop();
//            int a = stoi(s.top()); s.pop();
//            int res = 0;
//            if (tk == "+") res = a + b;
//            else if (tk == "-") res = a - b;
//            else if (tk == "*") res = a * b;
//            else if (tk == "/") res = a / b;
//            else if (tk == "%") res = a % b;
//            s.push(to_string(res));
//        }
//        s.show();
//    }
//    return stoi(s.top());
//}
//
//int evalPrefix(string exp) {
//    Stack s;
//    string t[100]; int n;
//    split(exp, t, n);
//    for (int i = n - 1; i >= 0; i--) {
//        string tk = t[i];
//        if (!isOp(tk)) s.push(tk);
//        else {
//            int a = stoi(s.top()); s.pop();
//            int b = stoi(s.top()); s.pop();
//            int res = 0;
//            if (tk == "+") res = a + b;
//            else if (tk == "-") res = a - b;
//            else if (tk == "*") res = a * b;
//            else if (tk == "/") res = a / b;
//            else if (tk == "%") res = a % b;
//            s.push(to_string(res));
//        }
//        s.show();
//    }
//    return stoi(s.top());
//}
//
//int main() {
//    string infix;
//    cout << "Enter Infix Expression: ";
//    getline(cin, infix);
//    int ch;
//    do {
//        cout << "1. Evaluate by Prefix\n2. Evaluate by Postfix\n3. Exit\nChoice: ";
//        cin >> ch;
//        cin.ignore();
//        if (ch == 1) {
//            string prefix = infixToPrefix(infix);
//            cout << "Prefix: " << prefix << endl;
//            cout << "Evaluation Process:" << endl;
//            int ans = evalPrefix(prefix);
//            cout << "Result: " << ans << endl;
//        }
//        else if (ch == 2) {
//            string postfix = infixToPostfix(infix);
//            cout << "Postfix: " << postfix << endl;
//            cout << "Evaluation Process:" << endl;
//            int ans = evalPostfix(postfix);
//            cout << "Result: " << ans << endl;
//        }
//    } while (ch != 3);
//    return 0;
//}