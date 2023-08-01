import { createContext, useState } from "react"
import type { ChartData } from "chart.js"

interface IWaveContext {
  data: ChartData
  updateWaveData: (newData: ChartData) => void
}

export const WaveContext = createContext<IWaveContext>({} as IWaveContext)

export function WaveContextProvider({
  children,
}: {
  children: React.ReactNode
}) {
  const [data, setData] = useState<ChartData>({
    labels: [],
    datasets: [
      {
        label: "",
        data: [],
      },
    ],
  })

  const updateWaveData = (newData: ChartData) => {
    setData(newData)
  }

  return (
    <WaveContext.Provider value={{ data, updateWaveData }}>
      {children}
    </WaveContext.Provider>
  )
}
