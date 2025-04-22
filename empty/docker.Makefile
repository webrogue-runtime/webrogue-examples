empty: empty.wrapp

empty.wrapp: main.wasm webrogue.json
	rm -f empty.wrapp
	webrogue pack -o empty.wrapp

clean:
	rm -f empty.wrapp
