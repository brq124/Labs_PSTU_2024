using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Program
{
    public class Program
    {
        const int UNIVERSUM_MIN = -30;
        const int UNIVERSUM_MAX = 30;
        public static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;
            List<HashSet<int>> sets = new List<HashSet<int>>();
            for (int i = 0; i < 3; i++)
            {
                sets.Add(new HashSet<int>());
            }
            HashSet<int> u = new HashSet<int>(); // универсум
            for (int i = UNIVERSUM_MIN; i <= UNIVERSUM_MAX; i++)
            {
                u.Add(i);
            }

            // ввод множеств
            int c = 0;
            while (c < 3)
            {
                Console.WriteLine($"Выберите способ задания {c + 1}-го множества:");
                Console.WriteLine("1. Ручной ввод");
                Console.WriteLine("2. Случайные значения");
                Console.WriteLine("3. По совокупности условий.");
                if (int.TryParse(Console.ReadLine(), out int op))
                {
                    Console.Clear();
                    switch (op)
                    {
                        case 1:
                            Console.WriteLine("Введите элементы множества через пробел");
                            try
                            {
                                sets[c] = Console.ReadLine().Split(' ').Select(int.Parse).ToHashSet();
                            }
                            catch
                            {
                                Console.WriteLine("Неверно введены элементы множества.");
                                Console.ReadKey();
                                Console.Clear();
                                continue;
                            }
                            break;
                        case 2:
                            Console.WriteLine("Введите размер множества");
                            if (int.TryParse(Console.ReadLine(), out int size) && size <= UNIVERSUM_MAX - UNIVERSUM_MIN + 1)
                            {
                                sets[c] = GetRandomSet(size, UNIVERSUM_MIN, UNIVERSUM_MAX);
                            }
                            else
                            {
                                Console.WriteLine("Неверное введено значение размера множества.");
                                Console.ReadKey();
                                Console.Clear();
                                continue;
                            }
                            break;
                        case 3:
                            List<Func<int, bool>> filter = new List<Func<int, bool>>();
                            Console.WriteLine("По знаку?");
                            Console.WriteLine("1. -");
                            Console.WriteLine("2. +");
                            Console.WriteLine("3. Нет");
                            if (int.TryParse(Console.ReadLine(), out op))
                            {
                                switch (op)
                                {
                                    case 0:
                                        break;
                                    case 1:
                                        filter.Add((x) => x < 0);
                                        break;
                                    case 2:
                                        filter.Add((x) => x > 0);
                                        break;
                                    case 3:
                                        break;
                                    default:
                                        Console.WriteLine("Неверно указан номер.");
                                        Console.ReadKey();
                                        Console.Clear();
                                        continue;
                                }
                            }
                            Console.Clear();
                            Console.WriteLine("По четности?");
                            Console.WriteLine("1. Да");
                            Console.WriteLine("2. Нет");
                            if (int.TryParse(Console.ReadLine(), out op))
                            {
                                switch (op)
                                {
                                    case 1:
                                        filter.Add((x) => x % 2 == 0);
                                        break;
                                    case 2:
                                        break;
                                    default:
                                        Console.WriteLine("Неверно указан номер.");
                                        Console.ReadKey();
                                        Console.Clear();
                                        continue;
                                }
                            }
                            Console.Clear();
                            Console.WriteLine("Укажите кратность (число)");
                            if (int.TryParse(Console.ReadLine(), out op) && op >= 1)
                            {
                                filter.Add((x) => x % op == 0);
                            }
                            else
                            {
                                Console.WriteLine("Неверно указано число.");
                                Console.ReadKey();
                                Console.Clear();
                                continue;
                            }

                            sets[c] = FillSetFilter(u, filter);
                            break;
                        default:
                            Console.WriteLine("Неверное значение оператора.");
                            Console.ReadKey();
                            Console.Clear();
                            continue;
                    }
                }
                c++;
                Console.Clear();
            }

            HashSet<int> selected_set_1 = u;
            HashSet<int> selected_set_2 = u;
            HashSet<int> result_set = u;
            while (true)
            {
                Console.WriteLine("Множества:");
                for (int i = 0; i < sets.Count; i++)
                {
                    Console.Write($"{i + 1}. ");
                    ShowSet(sets[i]);
                }
                Console.WriteLine("Выберите операцию:");
                Console.WriteLine("1. U Объединение");
                Console.WriteLine("2. ∩ Пересечение");
                Console.WriteLine("3. \\ Разность");
                Console.WriteLine("4. ∆ Симметричная разность");
                Console.WriteLine("5. ′ Дополнение");

                SetOperation oper;
                if (int.TryParse(Console.ReadLine(), out int op) && op >= 1 && op <= 5)
                {
                    oper = (SetOperation)op;
                }
                else
                {
                    Console.WriteLine("Неверно указан номер операции.");
                    Console.ReadKey();
                    Console.Clear();
                    continue;
                }

                if (oper == SetOperation.Complement)
                {
                    Console.WriteLine("Выберите множество");
                    if (int.TryParse(Console.ReadLine(), out int idx1) && idx1 >= 1 && idx1 <= sets.Count)
                    {
                        selected_set_1 = sets[idx1 - 1];
                    }
                    else
                    {
                        Console.WriteLine("Неверно указан номер множества.");
                        Console.ReadKey();
                        Console.Clear();
                        continue;
                    }
                }
                else
                {
                    Console.WriteLine("Выберите 1-ое и 2-ое множества");
                    if (int.TryParse(Console.ReadLine(), out int idx1) && idx1 >= 1 && idx1 <= sets.Count &&
                       int.TryParse(Console.ReadLine(), out int idx2) && idx2 >= 1 && idx2 <= sets.Count)
                    {
                        selected_set_1 = sets[idx1 - 1];
                        selected_set_2 = sets[idx2 - 1];
                    }
                    else
                    {
                        Console.WriteLine("Неверно указан номер(а) множеств.");
                        Console.ReadKey();
                        Console.Clear();
                        continue;
                    }
                }

                switch (oper)
                {
                    case SetOperation.Union:
                        result_set = Union(selected_set_1, selected_set_2);
                        break;
                    case SetOperation.Intersection:
                        result_set = Intersection(selected_set_1, selected_set_2);
                        break;
                    case SetOperation.Difference:
                        result_set = Difference(selected_set_1, selected_set_2);
                        break;
                    case SetOperation.SymmetricDifference:
                        result_set = SymmetricDifference(selected_set_1, selected_set_2);
                        break;
                    case SetOperation.Complement:
                        result_set = Complement(selected_set_1, u);
                        break;
                    default:
                        break;
                }

                Console.WriteLine("Полученное в результате множество:");
                ShowSet(result_set);
                if (!sets.Any(s => s.SetEquals(result_set)))
                {
                    Console.WriteLine("Сохранить множество? 1 - Да, 2 - Нет.");
                    string input = Console.ReadLine();
                    if (input.Equals("1")) sets.Add(result_set);
                }
                else
                {
                    Console.ReadKey();
                }
                Console.Clear();
            }
        }

        public static HashSet<int> FillSetFilter(HashSet<int> u, List<Func<int, bool>> filter)
        {
            HashSet<int> set = new HashSet<int>();
            foreach (int item in u)
            {
                if (filter.All(predicate => predicate(item)))
                {
                    set.Add(item);
                }
            }
            return set;
        }
        static Random rand = new Random();
        public static HashSet<int> GetRandomSet(int count, int min, int max)
        {
            if (count >= (max - min + 1))
            {
                throw new ArgumentException("Указанный размер множества не может превышать его максимальный возможный размер");
            }
            HashSet<int> set = new HashSet<int>();
            while (set.Count < count)
            {
                set.Add(rand.Next(min, max));
            }
            return set;
        }
        public static void ShowSet<T>(HashSet<T> set)
        {
            Console.Write("{");
            foreach (T item in set)
            {
                Console.Write($" {item}");
            }
            Console.WriteLine(" }");
        }

        enum SetOperation
        {
            Union = 1, // A ∪ B
            Intersection, // A ∩ B
            Difference, // A \ B
            SymmetricDifference, // A ∆ B
            Complement // A′
        }
        public static HashSet<T> Union<T>(HashSet<T> set1, HashSet<T> set2)
        {
            HashSet<T> result = new HashSet<T>(set1);
            foreach (T item in set2)
            {
                result.Add(item);
            }
            return result;
        }
        public static HashSet<T> Intersection<T>(HashSet<T> set1, HashSet<T> set2)
        {
            HashSet<T> result = new HashSet<T>();
            foreach (T item in set1)
            {
                if (set2.Contains(item))
                {
                    result.Add(item);
                }
            }
            return result;
        }
        public static HashSet<T> Difference<T>(HashSet<T> set1, HashSet<T> set2)
        {
            HashSet<T> result = new HashSet<T>(set1);
            foreach (T item in set2)
            {
                if (result.Contains(item))
                {
                    result.Remove(item);
                }
            }
            return result;
        }
        public static HashSet<T> SymmetricDifference<T>(HashSet<T> set1, HashSet<T> set2)
        {
            HashSet<T> result = Union(set1, set2);
            foreach (T item in set1)
            {
                if (set2.Contains(item))
                {
                    result.Remove(item);
                }
            }
            return result;
        }
        public static HashSet<T> Complement<T>(HashSet<T> set, HashSet<T> u)
        {
            HashSet<T> result = Difference(u, set);
            return result;
        }
    }
}

