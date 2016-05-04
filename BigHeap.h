#pragma once
#include<iostream>
#include<vector>
#include<assert.h>

using namespace std;

template<class T>
class BigHeap
{
public:
	//�޲ι��캯��
	BigHeap()
	{}
	//�вι��캯��
	BigHeap(const T* a, size_t size);
public:
	//����
	void Push(const T& d);
	//ɾ�����Ľڵ�
	void Pop();
	//��ӡ
	void Print();
protected:
	//���µ���
	void _AdjustDown(size_t parent);
	//���ϵ���
	void _AdjustUp(size_t child);
protected:
	vector<T> _a;//˳���
};

template<class T>
BigHeap<T>::BigHeap(const T* a, size_t size)
{
	//����
	assert(a);
	//��������������ݿ�����˳�����
	for (size_t i = 0; i < size; i++)
	{
		_a.push_back(a[i]);
	}

	//�������Ϲ�����

	//�ҵ���һ����Ҷ�ӽ�㲢�Ӻ���ǰ��ʼ�𲽵���
	for (int i = (_a.size() - 2) / 2; i >= 0; i--)
	{
		_AdjustDown(i);
	}

}

//���µ���
template<class T>
void BigHeap<T>::_AdjustDown(size_t parent)
{
	size_t child = parent * 2 + 1;//����
	while (child < _a.size())//�ж������Ƿ����
	{
		//�ҵ����Һ����нϴ��
		if (child + 1 < _a.size() && _a[child + 1] > _a[child])
		{
			child++;
		}

		//���ӽڵ�ȸ��׽ڵ�󣬽��������ٴε���
		if (_a[child]>_a[parent])
		{
			swap(_a[child], _a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		//���ӽڵ�ȸ��׽ڵ�С������Ҫ����
		else
		{
			break;
		}
	}

}

//���ϵ���
template<class T>
void BigHeap<T>::_AdjustUp(size_t child)
{
	size_t parent = (child - 1) / 2;
	while (parent<_a.size() && parent>=0)//�����׽ڵ�Ϊ���ڵ�ʱ���ٵ���
	{
		//������ӽڵ�ȸ��׽ڵ���򽻻�λ�ã����������ϵ���
		if (_a[child] > _a[parent])
		{
			swap(_a[child], _a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		//���ӽڵ�ȸ��׽ڵ�С����Ҫ����
		else
		{
			break;
		}
	}
}

//����
template<class T>
void BigHeap<T>::Push(const T& d)
{
	//���뵽˳�����
	_a.push_back(d);

	//���ϵ���
	_AdjustUp(_a.size() - 1);
}

//ɾ�����Ľڵ�
template<class T>
void BigHeap<T> ::Pop()
{
	//����˳���Ϊ��
	assert(!_a.empty());

	//������һ���ڵ�����һ���ڵ�
	swap(_a[0], _a[_a.size() - 1]);

	//ɾ�����һ���ڵ�
	_a.pop_back();

	//�ӵ�һ���ڵ㿪ʼ���µ���
	_AdjustDown(0);
}

//��ӡ
template<class T>
void BigHeap<T>::Print()
{
	for (size_t i = 0; i < _a.size(); i++)
	{
		cout << _a[i] << " ";
	}
	cout << endl;
}

void TestBigHeap()
{
	int a[] = { 10 ,11, 13, 12, 16, 18, 15 ,17 ,14, 19 };
	BigHeap<int> hp1(a, sizeof(a) / sizeof(a[0]));
	hp1.Print();
	cout << "Push:" << endl;
	hp1.Push(20);
	hp1.Print();
	hp1.Push(9);
	hp1.Print();
	cout << "Pop:" << endl;
	hp1.Pop();
	hp1.Print();
	hp1.Pop();
	hp1.Print();
}