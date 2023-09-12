#!/usr/bin/env python

a = { 'id': 89, 'name': "John", 'projects': [1, 2, 3, 4], 'friends': [ { 'id': 82, 'name': "Bob" }, { 'id': 83, 'name': "Amy" } ] }
a.get('friends')[-1].get("name")

b = { 'id': 89, 'name': "John", 'projects': [1, 2, 3, 4] }
b.get('projects')

for i in ["Hello", "Holberton", "School", 98]:
    print(i, end=" ")

for j in range(0, 3):
    print(j, end=" ")

h = { 'id': 89, 'name': "John" }
h.get('id')

m = { 'id': 89, 'name': "John", 'projects': [1, 2, 3, 4] }
m.get('projects')[3]