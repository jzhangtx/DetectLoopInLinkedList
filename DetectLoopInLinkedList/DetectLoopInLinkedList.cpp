// DetectLoopInLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//#define __STL_SET_ALLOWED__
#ifndef __STL_SET_ALLOWED__
#include <vector>
#else
#include <unordered_set>
#endif

class ListNode
{
public:
    int data;
    ListNode* next;
    ListNode(int data)
        : data(data)
        , next(nullptr)
    {}
};

ListNode* GetListFromInput(ListNode** ppHead, int count)
{
    if (count == 0)
        return nullptr;

    std::cout << "Enter " << count << " numbers of the list: ";
    ListNode* pTail = *ppHead;
    for (int i = 0; i < count; ++i)
    {
        int data = 0;
        std::cin >> data;
        if (*ppHead == nullptr)
        {
            *ppHead = new ListNode(data);
            pTail = *ppHead;
        }
        else
        {
            pTail->next = new ListNode(data);
            pTail = pTail->next;
        }
    }

    return pTail;
}

void PrintList(ListNode* pHead)
{
    std::cout << pHead->data;
    pHead = pHead->next;

    while (pHead != nullptr)
    {
        std::cout << ", " << pHead->data;
        pHead = pHead->next;
    }
}

void FreeList(ListNode* pNode)
{
    if (pNode == nullptr)
        return;

    FreeList(pNode->next);
    delete pNode;
}

ListNode* GetNodeByIndex(ListNode* pHead, int index)
{
    if (index == -1)
        return nullptr;

    for (int i = 0; i < index; ++i)
    {
        pHead = pHead->next;
    }

    return pHead;
}

#ifndef __STL_SET_ALLOWED__
bool NodeExists(std::vector<void*>& nodes, ListNode* node)
{
    for (auto n : nodes)
    {
        if (n == node)
            return true;
    }
    return false;
}

ListNode* StartingNodeOfLoop(ListNode* list)
{
    std::vector<void*> nodes;
    while (list != nullptr)
    {
        if (NodeExists(nodes, list))
            return list;

        nodes.push_back(list);
        list = list->next;
    }

    return nullptr;
}
#else
ListNode* StartingNodeOfLoop(ListNode* list)
{
    std::unordered_set<ListNode*> nodes;

    while (list != nullptr)
    {
        if (nodes.contains(list))
            return list;

        nodes.insert(list);
        list = list->next;
    }

    return nullptr;
}
#endif

ListNode* GetStartingNodeOfLoop(ListNode* list)
{
    return StartingNodeOfLoop(list);
}

int main()
{
    while (true)
    {
        int count = 0;
        std::cout << "Number of nodes in list: ";
        std::cin >> count;
        if (count == 0)
            break;

        ListNode* pHead = nullptr;
        ListNode* pTail = GetListFromInput(&pHead, count);

        std::cout << "The index of starting node of the loop: ";
        int index = -1;
        std::cin >> index;

        pTail->next = GetNodeByIndex(pHead, index);

        ListNode* pNode = GetStartingNodeOfLoop(pHead);
        std::cout << "Loop starts at node: " << (pNode != nullptr ? pNode->data : -1) << std::endl;
        pTail->next = nullptr;
        FreeList(pHead);
    }
}
