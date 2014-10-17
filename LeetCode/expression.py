def isPriority(a, b):
    return (a == '/' or a == '*') and (b == '+' or b == '0')

if __name__ == '__main__':
    s = "3+2*4/2+2*3/6"
    num_stack = []
    op_stack = []
    for i in range(len(s)):
        # print op_stack, num_stack
        if s[i] == '/' or s[i] == '*' or s[i] == '-' or s[i] == '+':
            op_stack.append(s[i])
        else:
            if (not num_stack) or (num_stack and i+1 < len(s) and isPriority(s[i+1], op_stack[-1])):
                num_stack.append(int(s[i]))
            else:
                op = op_stack.pop()
                a = int(num_stack.pop())
                b = int(s[i])
                # print a,b
                if (op == '-'):
                    num_stack.append(a - b)
                elif (op == '+'):
                    num_stack.append(a + b)
                elif (op == '/'):
                    num_stack.append(a / b)
                elif (op == '*'):
                    num_stack.append(a * b)

    while op_stack:
        op = op_stack.pop()
        b = int(num_stack.pop())
        a = int(num_stack.pop())
        if (op == '-'):
            num_stack.append(a - b)
        elif (op == '+'):
            num_stack.append(b + a)
        elif (op == '/'):
            num_stack.append(a / b)
        elif (op == '*'):
            num_stack.append(a * b)
    print num_stack
