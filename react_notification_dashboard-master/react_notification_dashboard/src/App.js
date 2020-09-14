import React, { useState, useEffect } from 'react';
import AlertsComponents from './components/AlertsComponents';
import data from './assets/data.json';
import styled from 'styled-components'

const app = styled.div`
  background-color: #fbfcfc;
`

function App() {
  const [alerts, setAlerts] = useState([]);

  useEffect(() => setAlerts(data), []);

  return (
    <app className="App">
      {alerts.length === 0 ? (
        <p>Alerts Fetching</p>
      ) : (
        alerts.map((alert) => <AlertsComponents alert={alert} key={alert.id} />)
      )}
    </app>
  );
}

export default App;
