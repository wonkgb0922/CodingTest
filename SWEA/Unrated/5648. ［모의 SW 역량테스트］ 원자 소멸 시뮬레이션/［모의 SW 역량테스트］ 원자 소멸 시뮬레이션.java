import java.util.*;
import java.io.*;

class Solution
{
	static int n;
	static int res;
	static boolean[] visited;
	static ArrayList<Atom> atoms = new ArrayList<>();
	static ArrayList<Record> records = new ArrayList<>();
	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        int i, j;
        for(int t = 1; t <= T; t++) {
        	atoms.clear();
        	records.clear();
        	n = Integer.parseInt(br.readLine());
        	for(int p = 0; p < n; p++) {
            	st = new StringTokenizer(br.readLine());
            	i = Integer.parseInt(st.nextToken());
            	j = Integer.parseInt(st.nextToken());
            	int d = Integer.parseInt(st.nextToken());
            	int k = Integer.parseInt(st.nextToken());
            	atoms.add(new Atom(j, i, d, k));
        	}
        	res = 0;
        	for(i = 0; i < n - 1; i++) {
    			Atom a = atoms.get(i);
        		for(j = i + 1; j < n; j++) {
        			// 두 개를 뽑아
        			Atom b = atoms.get(j);
        			// 같은 방향이면 만날 일이 없다~
        			if(a.d == b.d) continue;
        			if(a.d == 0) {
        				// 내가 위로 올라가는 중이라면
        				if(b.i < a.i) continue;
        				if(b.d == 1) {
            				// 얘는 위에서 아래로? -> j가 같아야 충돌
        					if(a.j == b.j) {
        						records.add(new Record(((a.i + b.i) / 2.) - Math.min(a.i, b.i), i, j));
        					}
        				}
        				else if(b.d == 3) {
            				// 얘는 왼쪽에서 날라오네
        					if(a.j > b.j) {
            					// 내가 더 오른쪽에 있어야돼
        						// 정사각형을 이루어야 해
        						if(a.j - b.j == b.i - a.i)
        							records.add(new Record(b.i - a.i, i, j));
        					}
        				}
        				else {
            				// 오른쪽에서 날라와
        					if(a.j < b.j) {
            					// 내가 더 왼쪽에 있어야돼
        						// 정사각형을 이루어야 해
        						if(b.j - a.j == b.i - a.i)
        							records.add(new Record(b.i - a.i, i, j));
        					}
        				}
        			}
        			else if(a.d == 1) {
        				// 나는 아래로 떨어져
        				// 쟤가 더 높으면 의미가 없지
        				if(a.i < b.i) continue;
        				if(b.d == 0) {
        					// 쟤는 위로 올라와
        					if(a.j == b.j) {
        						// 같은 열에만 성립
        						records.add(new Record(((b.i + a.i) / 2.) - Math.min(a.i, b.i), i, j));
        					}
        				}
        				else if(b.d == 3) {
            				// 얘는 왼쪽에서 날라오네
        					if(a.j > b.j) {
            					// 내가 더 오른쪽에 있어야돼
        						// 정사각형을 이루어야 해
        						if(a.j - b.j == a.i - b.i)
        							records.add(new Record(a.i - b.i, i, j));
        					}
        				}
        				else {
            				// 오른쪽에서 날라와
        					if(a.j < b.j) {
            					// 내가 더 왼쪽에 있어야돼
        						// 정사각형을 이루어야 해
        						if(b.j - a.j == a.i - b.i)
        							records.add(new Record(a.i - b.i, i, j));
        					}
        				}
        				
        			}
        			else if(a.d == 2) {
        				// 좌 (오른쪽에서 왼쪽 방향으로)
        				if(a.j < b.j) continue;
        				if(b.d == 3) {
        					// 왼쪽에서 날라온다면
        					if(a.i == b.i) {
        						// 같은 높이에서만 성립
        						records.add(new Record(((b.j + a.j) / 2.) - Math.min(a.j, b.j), i, j));
        					}
        				}
        				else if(b.d == 0) {
        					// 상 (밑에서 위로)
        					if(b.i < a.i) {
        						if(a.i - b.i == a.j - b.j) {
        							records.add(new Record(a.j - b.j, i, j));
        						}
        					}
        				}
        				else {
        					// 하(위에서 밑으로)
        					if(b.i > a.i) {
        						if(b.i - a.i == a.j - b.j) {
        							records.add(new Record(a.j - b.j, i, j));
        						}
        					}
        				}
        			}
        			else {
        				// 우
        				if(b.j < a.j) continue;
        				if(b.d == 2) {
        					// 오른쪽에서 날라온다면
        					if(a.i == b.i) {
        						// 같은 높이에서만 성립
        						records.add(new Record(((b.j + a.j) / 2.) - Math.min(a.j, b.j), i, j));
        					}
        				}
        				else if(b.d == 0) {
        					// 상 (밑에서 위로)
        					if(b.i < a.i) {
        						if(a.i - b.i == b.j - a.j) {
        							records.add(new Record(b.j - a.j, i, j));
        						}
        					}
        				}
        				else {
        					// 하(위에서 밑으로)
        					if(b.i > a.i) {
        						if(b.i - a.i == b.j - a.j) {
        							records.add(new Record(b.j - a.j, i, j));
        						}
        					}
        				}
        			}
        		}
        	}
        	visited = new boolean[n];
        	Collections.sort(records);
        	double curT = 0;
        	if(!records.isEmpty()) {
        		curT = records.get(0).t;
        	}
        	for(Record r : records) {
        		if(visited[r.idx1] || visited[r.idx2]) {
        			if(curT != r.t) {
            			continue;
        			}
        		}
        		curT = r.t;
        		if(!visited[r.idx1]) {
        			res += atoms.get(r.idx1).k;
        		}
        		if(!visited[r.idx2]) {
        			res += atoms.get(r.idx2).k;
        		}
        		visited[r.idx1] = true;
        		visited[r.idx2] = true;
        	}
        	
        	sb.append(String.format("#%d %d\n", t, res));
        }
        System.out.println(sb);
    }
	
}

class Atom {
	int i;
	int j;
	int d;
	int k;
	Atom(int i, int j, int d, int k) {
		this.i = i;
		this.j = j;
		this.d = d;
		this.k = k;
	}
}

class Record implements Comparable<Record> {
	double t;
	int idx1;
	int idx2;
	Record(double t, int idx1, int idx2) {
		this.t = t;
		this.idx1 = idx1;
		this.idx2 = idx2;
	}
	@Override
	public int compareTo(Record o) {
		return Double.compare(this.t, o.t);
	}
}