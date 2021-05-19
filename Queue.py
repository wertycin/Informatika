# Очередь
def new_node(value):
    return {
        'value': value,
        'next': None
    }

def new_queue():
    return {
        'head': None,
        'tail': None,
        'size': 0
    }

def enqueue(queue, value):
    tmp = new_node(value)
    if queue['size'] != 0:
        queue['tail']['next'] = tmp
    else:
        queue['head'] = tmp
    queue['tail'] = tmp
    queue['size'] += 1

def dequeue(queue):
    if queue['size'] == 0:
        print('queue is empty')
        return None
    value = queue['head']['value']
    queue['head'] = queue['head']['next']
    if queue['size'] == 1:
        queue['tail'] = None
    queue['size'] -= 1
    return value

def peek(queue):
    if not queue['size']:
        print('Queue is empty')
        return None
    return queue['head']['value']

#пример работы с очередью

queue = new_queue()
while True:
    cmd = input().split()
    if cmd[0] == 'exit':
        break
    if cmd[0] == 'add':
        enqueue(queue, cmd[1])
    elif cmd[0] == 'del':
        print(dequeue(queue))
    elif cmd[0] == 'peek':
        print(peek(queue))
    else:
        print('Incorrect command')

