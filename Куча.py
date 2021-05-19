# Куча
from math import ceil
# def sift_up(heap, pos):
#     while pos > 0 and heap[pos] < heap[pos//2]:
#         heap[pos], heap[pos//2] = heap[pos//2], heap[pos]
#         pos = pos//2

# def insert(heap, v):
#     heap.append(v)
#     sift_up(heap, len(heap) - 1)

def sift_down(heap, pos, n):
    while True:
        j = pos
        if 2*pos+1 < n and heap[j] > heap[2*pos+1]:
            j = 2*pos+1
        if 2*pos+2 < n and heap[j] > heap[2*pos+2]:
            j = 2*pos+2
        if pos == j:
            return
        heap[pos], heap[j] = heap[j], heap[pos]
        pos = j

# def extract_min(heap):
#     res = heap[0]
#     heap[0] = heap[-1]
#     heap.pop()
#     sift_down(heap,0)
#     return res

def build_heap(heap):
    n = len(heap)
    for i in range(ceil(len(heap)/2), -1, -1):
        sift_down(heap, i, n)

heap = list(map(int, input().split()))
build_heap(heap)
n = len(heap)
print(heap)
for i in range(len(heap)):
    heap[0], heap[n-1] = heap[n-1], heap[0]
    n -= 1
    sift_down(heap, 0, n)
    print(heap)
print(heap)



