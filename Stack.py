# Стек
def new_node(value):
    return {
        'value': value,
        'next': None
    }

def new_stack():
    return {
        'head': None,
        'size': 0
    }

def push(stack, value):
    tmp = new_node(value)
    tmp['next'] = stack['head']
    stack['head'] = tmp
    stack['size'] += 1

def pop(stack):
    if not stack['size']:
        print('Stack is empty')
        return None
    value = stack['head']['value']
    stack['head'] = stack['head']['next']
    stack['size'] -= 1
    return value

def peek(stack):
    if not stack['size']:
        print('Stack is empty')
        return None
    return stack['head']['value']

# для скобочной последовательности (()(
s = input()
stack = new_stack()
for e in s:
    if e == '(':
        push(stack, e)
    else:
        res = pop(stack)
        if res is None:
            print('NO')
            exit()
if stack['size']:
    print('NO')
else:
    print('YES')