namespace DynamicStructures
{
    public class Node<T> {
        public T Data { get; set; }
        public Node<T> Next { get; set; }

        internal Node(T value)
        {
            Data = value;
            Next = null;
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

    class CircularQueue<T> {
        private int Capacity { get; init; }
        private Node<T> front;
        private Node<T> rear;
        public int Size { get; private set; }

        public CircularQueue(int capacity)
        {
            Capacity = capacity;
            Size = 0;
            front = null;
            rear = null;
        }


        public bool IsEmpty()
        {
            return Size == 0;
        }


        public bool IsFull()
        {
            return Size == Capacity;
        }


        public void Enqueue(T value)
        {
            if(IsFull())
            {
                System.Console.WriteLine("Queue is full");
                return;
            }

            Node<T> newNode = new(value);
            if(IsEmpty())
            {
                front = newNode;
                rear = newNode;
            }
            else
            {

                // rear.Next = newNode;
                // rear = newNode;
            }
            rear.Next = front;
            Size += 1;
        }


        public T Dequeue()
        {
            if(IsEmpty())
            {
                throw new InvalidOperationException("Queue is Empty");
            }

            T data = front.Data;
            front = front.Next;
            rear.Next = front;
            Size -= 1;
            return data;
        }


        public T Peek()
        {
            if(IsEmpty())
            {
                throw new InvalidOperationException("Queue is Empty");
            }

            return front.Data;
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
                while (current.Next != null)
                {
                    current = current.Next;
                }
                current.Next = new(value);
            }
        }


        public void Print()
        {
            Node<T> current = node;
            while (current.Next != null)
            {
                System.Console.Write($"{current.Data} ");
                current = current.Next;
            }
        }
    }
}