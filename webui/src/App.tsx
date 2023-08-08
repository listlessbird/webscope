import {
  Route,
  RouterProvider,
  createBrowserRouter,
  createRoutesFromElements,
} from "react-router-dom"
import Saved from "./views/Saved"
import RootLayout from "./Layouts/RootLayout"
import Main from "./views/Main"

const routes = createBrowserRouter(
  createRoutesFromElements(
    <Route path="/" element={<RootLayout />}>
      <Route index element={<Main />} />
      <Route path="saved" element={<Saved />} />
    </Route>,
  ),
)

function App() {
  return <RouterProvider router={routes} />
}

export default App
