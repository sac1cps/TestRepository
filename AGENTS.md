# Repository Guidelines

## Project Structure & Module Organization
The repo is intentionally small: `app.js` hosts the Express server, `hello.c` is a standalone C demo, and `README.md` plus `LICENSE` clarify usage. The Node app expects view templates and static assets under `app/views` and `app/public`, and consumes structured data from `data/data.json`; add parallel directories when introducing new features so routing remains predictable. Keep route modules colocated with `app.js` (e.g., `routes/speakers.js`) and prefer descriptive filenames such as `routes/feedback.js` that mirror the URL path they serve.

## Build, Test, and Development Commands
- `npm install express reload socket.io ejs` — install the runtime dependencies since no lockfile is committed.
- `PORT=4000 node app.js` — boots the web server locally; change `PORT` to avoid collisions.
- `gcc hello.c -o hello && ./hello` — quick check that the sample C program still compiles and runs.
Use `nodemon app.js` if you need auto-reload during development; keep tooling in devDependencies when adding a `package.json`.

## Coding Style & Naming Conventions
Follow the existing 2-space indentation in `app.js` and prefer `const`/`let` when refactoring to newer syntax. Name Express routes, views, and data files after their purpose (`speakers`, `feedback`, etc.) and keep filenames lowercase-hyphenated. Validate JSON structure before committing, and run prettier/eslint if you add configs; default to commonjs modules for Node files.

## Testing Guidelines
There is no automated suite yet; when adding behavior, scaffold Jest or Mocha tests inside a top-level `tests/` folder mirrors the module tree (`tests/routes/speakers.test.js`). Name tests after the function or route under test, and gate merges on `npm test` succeeding. For `hello.c`, add simple assertions via `assert.h` and compile with `-Wall` to catch warnings.

## Commit & Pull Request Guidelines
Commit history favors short, declarative messages (e.g., "Test Commit of app.js"). Follow the format `<scope>: <summary>` when possible, and keep summaries under ~60 characters. PRs should describe the motivation, impacted files, manual test steps (`node app.js` log excerpt), and reference related issues. Include screenshots or terminal captures when UI or CLI output changes, and confirm lint/tests pass before requesting review.

## Security & Configuration Tips
The server trusts `PORT` and any environment data; never hard-code secrets. Validate user-provided feedback before persisting it, and keep dependency versions current to reduce Express/socket.io CVEs.
