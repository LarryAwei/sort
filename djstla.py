def generate_matrix():
    M = 1E100
    matrix = [[0, 4, M, 2, M],
              [4, 0, 4, 1, M],
              [M, 4, 0, 1, 3],
              [2, 1, 1, 0, 7],
              [M, M, 3, 7, 0]]
    return matrix


def dijkstra(matrix, source):
    M = 1E100
    n = len(matrix)
    found = [source]  # 已找到最短路径的节点
    cost = [M] * n  # source到已找到最短路径的节点的最短距离
    cost[source] = 0
    path = [[]] * n  # source到其他节点的最短路径
    path[source] = [source]
    while len(found) < n:
        min_value = M
        col = -1
        row = -1
        for f in found:  # 以已找到最短路径的节点所在行为搜索对象
            for i in [x for x in range(n) if x not in found]:  # 只搜索没找出最短路径的列
                if matrix[f][i] + cost[f] < min_value:
                    min_value = matrix[f][i] + cost[f]
                    row = f  # 记录所在行列
                    col = i
        if col == -1 or row == -1:
            break
        found.append(col)  # 在found中添加已找到的节点
        cost[col] = min_value  # source到该节点的最短距离即为min_value
        path[col] = path[row][:]  # 复制source到已找到节点的上一节点的路径
        path[col].append(col)  # 再其后添加已找到节点即为sorcer到该节点的最短路径
    return found, cost, path


def main():
    matrix = generate_matrix()
    found, cost, path = dijkstra(matrix, 0)
    print('found:')
    print(found)
    print('cost:')
    print(cost)
    print('path:')
    for p in path:
        print(p)


if __name__ == '__main__':
    main()
