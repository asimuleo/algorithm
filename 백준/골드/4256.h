#include <iostream>

using namespace std;

int T; // 테스트 케이스
int n; // 노드의 개수

struct node
{
    node* left = nullptr;
    node* right = nullptr;
    int num;
    int index;
};

void print_post_order(const node& root)
{
    if (root.left != nullptr)
        print_post_order(*root.left);
    if (root.right != nullptr)
        print_post_order(*root.right);
    cout << root.num << " ";
}

// 각 테스트 케이스마다 후위 순회한 결과를 출력 한다.
int p_4256()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--)
    {
        cin >> n;
        // 전위 순회
        int pre_order[n];
        for (int i = 0; i < n; i++)
        {
            cin >> pre_order[i];
        }
        // 중위 순회
        node in_order[n];
        int in_order_index[n + 1]; // 인덱스
        for (int i = 0; i < n; i++)
        {
            cin >> in_order[i].num;
            in_order[i].index = i;
            in_order_index[in_order[i].num] = i;
        }

        node& root = in_order[in_order_index[pre_order[0]]];

        for (int i = 1; i < n; i++)
        {
            int cur = pre_order[i];
            node& n = in_order[in_order_index[cur]];

            node* point = &root;

            while (true)
            {
                if (n.index < point->index)
                {
                    if (point->left == nullptr)
                    {
                        point->left = &n;
                        break;
                    }
                    point = point->left;
                }
                else
                {
                    if (point->right == nullptr)
                    {
                        point->right = &n;
                        break;
                    }
                    point = point->right;
                }
            }

        }

        // 후위 순회 출력
        print_post_order(root);
        cout << endl;
    }

    return 0;
}
