import sys

def check_for_bench_flag(parts):
  for i in range(len(parts)):
    if parts[i] == '[BENCH_CONTEXT_SWITCHING]':
      return parts[i+1:]
  return False

def average(tab):
  if len(tab) == 0:
    return 0

  sum = 0
  for el in tab:
    sum += el
  return sum / len(tab)


dic = {}

for line in sys.stdin:
  splt = line.split()
  parts = check_for_bench_flag(splt)

  # Pass if there is no bench flag
  if not parts:
    continue
  
  from_id = parts[0]
  to_id = parts[1]
  time_us = int(parts[2])
  if (from_id, to_id) not in dic:
    dic[(from_id, to_id)] = [time_us]
  else:
    dic[(from_id, to_id)].append(time_us)
  print(chr(27) + "[2J") # Clean
  print("Time from {} thread to {} thread: {} microseconds".format(from_id, to_id, time_us))
  print("Average from {} thread to {} thread: {} microseconds".format(from_id, to_id, average(dic[from_id, to_id])))
