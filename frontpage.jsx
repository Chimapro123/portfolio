 import React, { useState } from "react";

function App() {
  const [problem, setProblem] = useState("");
  const [response, setResponse] = useState("");

  const handleSubmit = (event) => {
    event.preventDefault();

    if (problem.trim() === "") {
      setResponse("Please describe your problem first.");
      return;
    }

    setResponse(
      "Thank you for sharing your problem. CareryDave will help you find the right healthcare information."
    );
  };

  return (
    <div className="app">
      <header className="header">
        <h1>CareryDave</h1>
        <p>Your personal healthcare companion</p>

      </header>

      <main className="main-content">
        <h2>How are you feeling today?</h2>

        <form onSubmit={handleSubmit}>
          <textarea
            placeholder="Tell CareryDave about your problem..."
            value={problem}
            onChange={(event) => setProblem(event.target.value)}
          ></textarea>

          <button type="submit">Get Help</button>
        </form>

        {response && (
          <div className="response">
            <p>{response}</p>
          </div>
        )}
      </main>
    </div>
  );
}

export default App;