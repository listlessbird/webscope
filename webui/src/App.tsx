import ChannelTable from "./components/ChannelTable"
import Header from "./components/Header"
import PlotView from "./components/PlotView"
import { WaveContextProvider } from "./context/index"

function App() {
  return (
    <main className="pr-[1rem] pl-[1rem]">
      <Header />\
      <WaveContextProvider>
        <PlotView />
        <ChannelTable channelName="channel 1" />
      </WaveContextProvider>
    </main>
  )
}

export default App
