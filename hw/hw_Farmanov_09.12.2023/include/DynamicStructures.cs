using System.Collections.Concurrent;

namespace DynamicStructures
{
    public class Node<T> {
        public T value;
        public Node<T> next;

        internal Node(T value)
        {
            this.value = value;
        }
    }

    public class PriorityQueue<T> where T: IComparable {
        private List<T> heap;
        public int Size { get { return heap.Count; } }

        public PriorityQueue()
        {
            heap = new List<T>();
        }


        public void Enqueue(T item)
        {
            heap.Add(item);
            HeapifyUp(heap.Count - 1);
        }


        public T Dequeue()
        {
            if (heap.Count == 0)
            {
                throw new InvalidOperationException("Queue is empty");
            }

            T min = heap[0];
            int lastIndex = heap.Count - 1;

            if (lastIndex == 0)
            {
                heap.RemoveAt(0);
            }
            else
            {
                heap[0] = heap[lastIndex];
                heap.RemoveAt(lastIndex);
                HeapifyDown(0);
            }

            return min;
        }


        private void HeapifyUp(int lowerIndex)
        {
            if (lowerIndex <= 0)
            {
                return;
            }

            int upperIndex = (lowerIndex - 1) / 2;
            if (heap[lowerIndex].CompareTo(heap[upperIndex]) < 0)
            {
                Swap(lowerIndex, upperIndex);
                HeapifyUp(upperIndex);
            }
        }


        private void HeapifyDown(int upperIndex)
        {
            int leftLowerIndex = upperIndex * 2 + 1;
            int rightLowerIndex = leftLowerIndex * 2 + 2;
            int minimal = upperIndex;

            if (leftLowerIndex < heap.Count && heap[leftLowerIndex].CompareTo(heap[minimal]) < 0)
            {
                minimal = leftLowerIndex;
            }

            if (rightLowerIndex < heap.Count && heap[rightLowerIndex].CompareTo(heap[minimal]) < 0)
            {
                minimal = rightLowerIndex;
            }

            if (minimal != upperIndex)
            {
                Swap(upperIndex, minimal);
                HeapifyDown(minimal);
            }
        }


        private void Swap(int vertex_1, int vertex_2)
        {
            (heap[vertex_1], heap[vertex_2]) = (heap[vertex_2], heap[vertex_1]);
        }
    }

    public class SigleLinkedList<T> {
        public Node<T> node;

        public SigleLinkedList(params T[] values)
        {
            foreach (var item in values)
            {
                PushBack(item);
            }
        }


        public bool IsEmpty()
        {
            return node == null;
        }


        public void PushBack(T value)
        {
            if(IsEmpty())
            {
                node = new(value);
            }
            else
            {
                Node<T> current = node;
                while (current.next != null)
                {
                    current = current.next;
                }
                current.next = new(value);
            }
        }


        public void Print()
        {
            Node<T> current = node;
            while (current.next != null)
            {
                System.Console.Write($"{current.value} ");
                current = current.next;
            }
        }
    }
}